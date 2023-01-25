#include "Board.h"
#include "Square.h"
#include<iostream>


Board::Board() : mRow(16), mCol(16)
{
	mSquares.resize(16);
	for (auto& sqs : mSquares)
	{
		sqs.resize(mCol);
		for (auto& sq : sqs)
		{
			shared_ptr<Square> p(new Square);
			sq = p;
		}
	}
}

void Board::Display()
{
	cout << " ";
	for (int i = 0; i < mRow; ++i)
	{
		cout << "+";
	}
	cout << endl;
	for (int i = 0; i < mRow; ++i)
	{
		cout << "+";
		for (int j = 0; j < mCol; ++j)
		{
			mSquares.at(i).at(j)->GetIsLive() ?
				cout << "#" :
				cout << " ";
		}
		cout << endl;
	}
}

void Board::ToggleSquare(int row, int col)
{
	mSquares.at(row).at(col)->Toggle();
}