#pragma once
#include<memory>

using namespace std;

class LifeGame
{
public:
	LifeGame();
	void Input();
	void Prosses();
	void Output();
	bool GetGameOver() { return mGameOver; }
private:
	shared_ptr<class Board> mBoards[2];
	int mCurrentBoard;
	bool mGameOver;
};