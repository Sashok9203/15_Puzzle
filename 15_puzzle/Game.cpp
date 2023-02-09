#include "Game.h"

Game::Game(int size):size(size), steps(0), pivot(Point { size - 1,size - 1 })
{
	if (size < 3 || size > 9) throw std::exception("Invalid table size...3 - 9");
	table = new int* [size] {};
	for (int i = 0; i < size; i++)
	{
		table[i] = new int[size];
		for (int k = 0; k < size; k++)
		{
			table[i][k] = i * size + k + 1;
		}
	}
	showCursor(false);
}

Game::~Game()
{
	for (int i = 0; i < size; i++)
	{
		delete[] table[i];
	}
	delete[] table;
}

void Game::shake(int count)
{
	int row, col, row2, col2;
	while (count)
	{
		row = randomRange(0, size - 1);
		col = randomRange(0, size - 1);
		row2 = randomRange(0, size - 1);
		col2 = randomRange(0, size - 1);
		std::swap(table[row][col], table[row2][col2]);
		--count;
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t k = 0; k < size; k++)
		{
			if (table[i][k] == size * size)
			{
				pivot.row = i;
				pivot.col = k;
				return;
			}
		}
	}
}

void Game::printGameTable() const
{
	setCursor(4, 4);
	std::cout << std::endl << "              Moves -> " << steps << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			std::cout << "              " << (char)201 << (char)205 << (char)205 << (char)205 << (char)203;
			for (int i = 0; i < size - 2; i++)
			{
				std::cout << (char)205 << (char)205 << (char)205 << (char)203;
			}
			std::cout << (char)205 << (char)205 << (char)205 << (char)187 << std::endl;
		}
		std::cout << "              ";
		for (int k = 0; k < size; k++)
		{
			if (k == 0) std::cout << (char)186;
			if (table[i][k] != size * size)
			{
				if (table[i][k] < 10)std::cout << " " << table[i][k] << " ";
				else std::cout << table[i][k] << " ";
			}
			else std::cout << "   ";
			std::cout << (char)186;
		}
		std::cout << std::endl;
		if (i != size - 1)
		{
			std::cout << "              " << (char)204 << (char)205 << (char)205 << (char)205 << (char)206;
			for (int i = 0; i < size - 2; i++)
			{
				std::cout << (char)205 << (char)205 << (char)205 << (char)206;
			}
			std::cout << (char)205 << (char)205 << (char)205 << (char)185 << std::endl;
		}
		else if (i == size - 1)
		{
			std::cout << "              " << (char)200 << (char)205 << (char)205 << (char)205 << (char)202;
			for (int i = 0; i < size - 2; i++)
			{
				std::cout << (char)205 << (char)205 << (char)205 << (char)202;
			}
			std::cout << (char)205 << (char)205 << (char)205 << (char)188 << std::endl;
		}
	}
	std::cout << std::endl;
}

bool Game::check()
{
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size; k++)
		{
			if (table[i][k] != i * size + k + 1) return false;
		}
	}
	return true;
}

void Game::playerMove(Arrows move)
{
	Point oldPos = pivot;
	switch (move)
	{
	case arrow_right:
		if (pivot.col + 1 <= size - 1)
		{
			std::swap(table[pivot.row][pivot.col + 1], table[pivot.row][pivot.col]);
			pivot.col = pivot.col + 1;
		}
		break;
	case arrow_down:
		if (pivot.row + 1 <= size - 1)
		{
			std::swap(table[pivot.row + 1][pivot.col], table[pivot.row][pivot.col]);
			pivot.row = pivot.row + 1;
		}
		break;
	case arrow_left:
		if (pivot.col - 1 >= 0)
		{
			std::swap(table[pivot.row][pivot.col - 1], table[pivot.row][pivot.col]);
			pivot.col = pivot.col - 1;
		}
		break;
	case arrow_up:
		if (pivot.row - 1 >= 0)
		{
			std::swap(table[pivot.row - 1][pivot.col], table[pivot.row][pivot.col]);
			pivot.row = pivot.row - 1;
		}
	}
	if (oldPos != pivot) ++steps;
}


