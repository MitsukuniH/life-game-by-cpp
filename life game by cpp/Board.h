#pragma once
#include<vector>
#include<memory>

using namespace std;

class Board
{
public:
	Board();
	void Display();
	void Prosses();
	int GetRow() { return mRow; }
	int GetCol() { return mCol; }
private:
	int mRow;
	int mCol;
	vector <vector<shared_ptr<class Square >>> mSquares;
};