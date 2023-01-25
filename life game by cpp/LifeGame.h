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
	pair<shared_ptr<class Board>, shared_ptr<class Board>> mBoards;
	bool mGameOver;
};