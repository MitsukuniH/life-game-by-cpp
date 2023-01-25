#include "LifeGame.h"
#include "Board.h"
#include "Square.h"
#include<iostream>

using namespace std;

LifeGame::LifeGame() : mGameOver(false)
{
	shared_ptr<Board> pf(new Board);
	mBoards.first = pf;
	shared_ptr<Board> ps(new Board);
	mBoards.second = ps;
}

void LifeGame::Input()
{
	bool end = false;
	char command;
	cout << "continue: c | toggle_square: t | display: d | Clear: C | quit: q" << endl;
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
		case 'd':
			mBoards.first->Display();
			break;
		case 'C':
			mBoards.first->Clear();
			mBoards.second->Clear();
			break;
		case 'q':
			end = true;
			mGameOver = true;
			break;
		default:
			cout << command << " is an incorrect command" << endl;
			break;
		}
	}
}

void LifeGame::toggleSquare()
{
	int row, col;
	cout << "row col >> ";
	cin >> row >> col;
	mBoards.first->ToggleSquare(row, col);
	mBoards.second->ToggleSquare(row, col);
}

void LifeGame::Prosses()
{
	mBoards.second->Prosses(mBoards.first);
	mBoards.first->Copy(mBoards.second);
}

void LifeGame::Output()
{
	mBoards.first->Display();
}