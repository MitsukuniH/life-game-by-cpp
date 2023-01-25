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
	int a = 5 % 4;
	cout << a << endl;
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
	if (row < 0 || row >= mRow || col < 0 || col >= mCol)
	{
		cout << "error: incorrect value" << endl;
		return;
	}
	mSquares.at(row).at(col)->Toggle();
}

void Board::Prosses(shared_ptr<Board> front)
{
	int dir[8][2] = {
		{-1, -1 }, {0, -1}, {1, -1},
		{-1,  0 },          {1,  0},
		{-1,  1 }, {0,  1}, {1,  1}
	};

	for (int i = 0;i < mRow; ++i)
	{
		for (int j = 0;j < mCol; ++j)
		{
			int liveNumber = 0;
			for (auto d : dir)
			{
				int r = i + d[0];
				int c = j + d[1];
				if (r < 0) r = mRow + r;
				else if (r >= mRow) r %= mRow;
				if (c < 0) c = mRow + c;
				else if (c >= mRow) c %= mRow;

				if (mSquares.at(r).at(c)->GetIsLive()) ++liveNumber;
			}

			bool isLive = false;
			if (mSquares.at(i).at(j)->GetIsLive())
			{
				if (liveNumber == 2 || liveNumber == 3) isLive = true;
			}
			else
			{
				if (liveNumber == 3) isLive = true;
			}

			front->GetSquares().at(i).at(j)->SetIsLive(isLive);
		}
	}
}

void Board::Copy(shared_ptr<Board> dest)
{
	for (int i = 0; i < mRow; ++i)
	{
		for (int j = 0; j < mRow; ++j)
		{
			dest->GetSquares().at(i).at(j)->SetIsLive(
				mSquares.at(i).at(j)->GetIsLive()
			);
		}
	}
}

void Board::Clear()
{
	for (auto& sqs : mSquares)
	{
		for (auto& sq : sqs)
		{
			sq->SetIsLive(false);
		}
	}
}