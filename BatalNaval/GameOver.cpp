#include <iostream>
#include "batal.h"


void TestGameOver(Batal playerOne, Batal playerTwo){
	if (playerOne.health <= 0)
	{
		std::cout << "PLAYER 2 WIN" << '\n';
	}
	else if (playerTwo.health <= 0) {
		std::cout << "PLAYER 1 WIN" << '\n';

	}
}