#include "LifeGame.h"
#include "Board.h"
#include "Square.h"
#include<iostream>

using namespace std;

LifeGame::LifeGame() : mGameOver(false)
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
			toggleSquare();
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

void LifeGame::toggleSquare()
{
	int row, col;
	cout << "row col >> ";
	cin >> row >> col;
	mBoards[0]->ToggleSquare(row, col);
	mBoards[1]->ToggleSquare(row, col);
}

void LifeGame::Prosses()
{

}

void LifeGame::Output()
{
	mBoards[0]->Display();
}