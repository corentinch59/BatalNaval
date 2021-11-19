
#include <iostream>
#include <vector>
#include "TurnSystem.h"
#include "batal.h"

std::vector<Batal> InitialiseList(Batal& player1, Batal& player2) {
	std::vector<Batal> newList;

	newList.push_back(player1);
	newList.push_back(player2);

	return newList;
}

std::vector<Batal>::iterator InitialiseTurn(std::vector<Batal>& list, Turn& turn) {
	std::vector<Batal>::iterator newIt;

	turn.step = 0;
	newIt = list.begin();

	return newIt;
}

void StartingPhase(std::vector<Batal>::iterator& it, Turn& turn) {
	//Start the phase check if fishing or batal on fire.
	if (turn.step == 0) {
		std::vector<BatalEffects>::iterator batalFxIt;
		for (batalFxIt = it->listOfEffects.begin(); batalFxIt != it->listOfEffects.end();) {
			switch (batalFxIt->batalStatus)
			{
			case RainBuff:
				for (auto rb = it->listOfEffects.begin(); rb != it->listOfEffects.end();) {
					switch (rb->batalStatus)
					{
					case fireDebuff: case voidDebuff:
						std::cout << rb->batalStatus << " cleansed" << '\n';
						it->listOfEffects.erase(rb);
					default:
						rb++;
						break;
					}
				}
				it->listOfEffects.erase(batalFxIt);
				break;
			default:
				batalFxIt++;
				break;
			}
		}
		for (batalFxIt = it->listOfEffects.begin(); batalFxIt != it->listOfEffects.end();) {
			switch (batalFxIt->batalStatus)
			{
			case voidDebuff:
				if (batalFxIt->duration != 0) {
					batalFxIt->duration -= 1;
					it->damageMult = 2;
				}
				if (batalFxIt->duration == 0) {
					it->damageMult = 1;
					std::cout << "VoidDebuff expired" << '\n';
					it->listOfEffects.erase(batalFxIt);
				}
				else {
					batalFxIt++;
				}
				break;
			case fireDebuff:
				if (batalFxIt->duration != 0) {
					batalFxIt->duration -= 1;
					//Damage the Batal
				}
				if (batalFxIt->duration == 0) {
					std::cout << "FireDebuff expired" << '\n';
					it->listOfEffects.erase(batalFxIt);
				}
				else {
					batalFxIt++;
				}
				break;
			case FishBuff:
				break;
			}
		}
	turn.step = 1;
	}
}

bool CheckActionPhase(Turn& turn) {
	if (turn.step == 1) {
		return true;
	}
	else
		return false;
}

void ResolveActionPhase(Turn& turn) {
	turn.step = 2;
}

std::vector<Batal>::iterator EndPhase(std::vector<Batal> list, std::vector<Batal>::iterator& it, Turn& turn) {
	if (turn.step == 2) {
		it++;
		if (it == list.end()) {
			it = list.begin();
		}
	}
	return it;
}