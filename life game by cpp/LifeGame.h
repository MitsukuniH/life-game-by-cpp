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
	void toggleSquare();
	shared_ptr<class Board> mBoards[2];
	bool mGameOver;
};