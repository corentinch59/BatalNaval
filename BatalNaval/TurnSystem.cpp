
#include "TurnSystem.h"
#include "batal.h"

std::vector<Batal> InitialiseList(Batal& player1, Batal& player2) {
	std::vector<Batal> newList;

	newList.push_back(player1);
	newList.push_back(player2);

	return newList;
}

std::vector<Batal>::iterator InitialiseTurn(std::vector<Batal>& list) {
	std::vector<Batal>::iterator newIt;

	newIt = list.begin();

	return newIt;
}

void StartingPhase(std::vector<Batal>::iterator& it) {
	//TODO: start the phase check if fishing or batal on fire.
}

void ActionPhase(std::vector<Batal>::iterator& it) {
	/*TODO: wait for player input between :
	- Shoot
	- Rain
	- Start fishing*/
}

std::vector<Batal>::iterator EndPhase(std::vector<Batal>::iterator& it) {
	//TODO: change iterator to the other batal
}