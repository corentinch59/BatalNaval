#pragma once
#include "batal.h"

struct Turn {
	std::vector<Batal> bList;
	int step;
};

std::vector<Batal> InitialiseList(Batal& player1, Batal& player2);

std::vector<Batal>::iterator InitialiseTurn(std::vector<Batal>& list, Turn& turn);

void StartingPhase(std::vector<Batal>::iterator& it, Turn& turn);

bool CheckActionPhase(Turn& turn);

void ResolveActionPhase(Turn& turn);

std::vector<Batal>::iterator EndPhase(std::vector<Batal> list, std::vector<Batal>::iterator& it, Turn& turn);
