#include "LifeGame.h"
#include "Board.h"
#include "Square.h"
#include<iostream>

using namespace std;

LifeGame::LifeGame() : mCurrentBoard(0), mGameOver(false)
{
	for (auto& board : mBoards)
	{
		shared_ptr<Board> p(new Board);
		board = p;
	}
}

void LifeGame::Input()
{
	bool end = false;
	char command;
	cout << "continue: c toggle_square: t quit: q" << endl;
	while (!end)
	{
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 'c':
			end = true;
			break;
		case 't':
			break;
		case 'q':
			end = true;
			mGameOver = true;
			break;
		default:
			cout << command << "is an incorrect command" << endl;
			break;
		}
	}
}

void LifeGame::Prosses()
{

}

void LifeGame::Output()
{
	mBoards[mCurrentBoard]->Display();
}