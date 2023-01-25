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
		lg.Output();
		lg.Input();
		lg.Prosses();
	}
	return 0;
}