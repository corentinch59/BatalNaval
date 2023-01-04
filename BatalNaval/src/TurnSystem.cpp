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

void InitialiseTurn(Turn& turn) {

	turn.step = 0;
	turn.itBatal = turn.bList.begin();

	return;
}

void StartingPhase(Turn& turn) {
	//Start the phase check if fishing or batal on fire.
	if (turn.step == 0) {
		std::vector<BatalEffects>::iterator batalFxIt;
		for (batalFxIt = turn.itBatal->listOfEffects.begin(); batalFxIt != turn.itBatal->listOfEffects.end();) {
			switch (batalFxIt->batalStatus)
			{
			case RainBuff:
				for (auto rb = turn.itBatal->listOfEffects.begin(); rb != turn.itBatal->listOfEffects.end();) {
					switch (rb->batalStatus)
					{
					case fireDebuff: case voidDebuff:
						std::cout << rb->batalStatus << " cleansed" << '\n';
						turn.itBatal->listOfEffects.erase(rb);
					default:
						rb++;
						break;
					}
				}
				turn.itBatal->listOfEffects.erase(batalFxIt);
				break;
			default:
				batalFxIt++;
				break;
			}
		}
		for (batalFxIt = turn.itBatal->listOfEffects.begin(); batalFxIt != turn.itBatal->listOfEffects.end();) {
			switch (batalFxIt->batalStatus)
			{
			case voidDebuff:
				if (batalFxIt->duration != 0) {
					batalFxIt->duration -= 1;
					turn.itBatal->damageMult = 2;
				}
				if (batalFxIt->duration == 0) {
					turn.itBatal->damageMult = 1;
					std::cout << "VoidDebuff expired" << '\n';
					turn.itBatal->listOfEffects.erase(batalFxIt);
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
					turn.itBatal->listOfEffects.erase(batalFxIt);
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
	return;
}

void EndPhase(Turn& turn) {
	if (turn.step == 2) {
		turn.itBatal++;
		if (turn.itBatal == turn.bList.end()) {
			turn.itBatal = turn.bList.begin();
		}
	}
	return;
}