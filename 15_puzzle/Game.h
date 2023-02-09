#pragma once
#include <iostream>
#include "MyProc.h"
enum Arrows                                                             // ����������� � ������ ����� � ��������
{
	arrow_up = 80,
	arrow_right = 75,
	arrow_left = 77,
	arrow_down = 72
};
class Game
{
private:
	struct Point                                                             //��������� ��� ������ ���������� ������� ��������
	{
		int row {};
		int col {};
		bool operator != (Point value)                                       //���������������� �������� ��� �������� �� ������������� ������� ���� �������� pivot
		{
			return (this->col != value.col) || (this->row != value.row);
		}
	};


	int** table;
	int size;
	int steps;
	Point pivot;
public:
	Game(int size);
	~Game();
	void shake(int count);
	bool check();
	void printGameTable() const;
	void playerMove(Arrows move);
	int getSteps() const { return steps; }
};

