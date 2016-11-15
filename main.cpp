#include <iostream>
using namespace std;
#include "Game.h"

#include <time.h>
#include<conio.h>

int main()
{
	
	system("cls");
	HideCursor();
	//startMenu();
	
	//drawMenu();
	welcomeMenu();

	
	system("cls");
	ConsoleGame game;
	int temp = startMenu();
	if(temp = 15)
		game.setLevelOfGame(secondSpeed);
	playingMenu();
	game.playingCtrl();
	
	
	return 0;
}
