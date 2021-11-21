#pragma once
#include "batal.h"

struct Turn {
	std::vector<Batal> bList;
	int step;
	std::vector<Batal>::iterator itBatal;
};

std::vector<Batal> InitialiseList(Batal& player1, Batal& player2);

void InitialiseTurn(Turn& turn);

void StartingPhase(Turn& turn);

bool CheckActionPhase(Turn& turn);

void ResolveActionPhase(Turn& turn);

void EndPhase(Turn& turn);
