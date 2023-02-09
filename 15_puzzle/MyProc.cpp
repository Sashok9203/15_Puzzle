#include "MyProc.h"

void setCursor(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { (short)x,(short)y });
}
void showCursor(bool visible)
{
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = visible;
	ccInfo.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ccInfo);
}
int randomRange(int left, int right)
{
	static bool is_first = true;
	if (is_first)
	{
		srand(unsigned(time(0)));
		is_first = false;
	}
	return left + rand() % (right - left + 1);
}