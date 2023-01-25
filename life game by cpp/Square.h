#pragma once
class Square
{
public:
	Square();
	void Toggle();
	bool GetIsLive() { return mIsLive; }
private:
	bool mIsLive;
};