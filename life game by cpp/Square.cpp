#include "Square.h"
Square::Square() : mIsLive(false)
{};

void Square::Toggle()
{
	mIsLive = !mIsLive;
}
