#include <iostream>
#include "GameOver.h"



void TestGameOver(Batal playerOne, Batal playerTwo, bool& isGameOver){
	if (playerOne.health <= 0)
	{
		std::cout << "PLAYER 2 WIN" << '\n';
		isGameOver = true;
	}
	else if (playerTwo.health <= 0) {
		std::cout << "PLAYER 1 WIN" << '\n';
		isGameOver = true;
	}
}
