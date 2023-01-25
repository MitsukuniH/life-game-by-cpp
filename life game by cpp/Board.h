#pragma once
#include<vector>
#include<memory>

using namespace std;

class Board
{
public:
	Board();
	void Display();
	void Prosses(shared_ptr<Board>);
	void ToggleSquare(int, int);
	void Clear();
	int GetRow() { return mRow; }
	int GetCol() { return mCol; }
	vector <vector<shared_ptr<class Square >>> GetSquares() { return mSquares; }
	void Copy(shared_ptr<Board>);
private:
	int mRow;
	int mCol;
	vector <vector<shared_ptr<class Square >>> mSquares;
};