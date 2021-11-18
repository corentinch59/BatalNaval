#pragma once

#include <iostream>
#include <vector>

struct Turn {
	std::vector<Batal> bList;
	int step;
};

std::vector<Batal> InitialiseList(Batal& player1, Batal& player2);

std::vector<Batal>::iterator InitialiseTurn(std::vector<Batal>& list);
