#include<iostream>
#include<vector>
#include<memory>

#include "LifeGame.h"

using namespace std;

int main()
{
	LifeGame lg;
	while (!lg.GetGameOver())
	{
		lg.Input();
		lg.Prosses();
		lg.Output();
	}
	return 0;
}