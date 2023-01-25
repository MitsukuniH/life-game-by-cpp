#pragma once
class Square
{
public:
	Square();
	void Toggle();
	bool GetIsLive() { return mIsLive; }
	void SetIsLive(bool islive) { mIsLive = islive; }
private:
	bool mIsLive;
};