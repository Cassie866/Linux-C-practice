#include "game2048.h"

Game2048::Game2048()
	:status(S_NORMAL)
{
	SetTestData();
}

int Game2048::GetStatus()
{
	return status;
}

void Game2048::ProcessInput()
{
	char ch = getchar();
	if (ch >= 'a' && ch <= 'z')
	{
		ch -= 32;
	}
	if (status == S_NORMAL)
	{
		bool updated = false;
		if (ch == 'A')
		{
			updated = MoveLeft();
		}
		else if (ch == 'S')
		{
			Rotate();
			Rotate();
			Rotate();
			updated = MoveLeft();
			Rotate();
		}
		else if (ch == 'W')
		{
			Rotate();
			updated = MoveLeft();
			Rotate();
			Rotate();
			Rotate();
		}
		if (updated)
		{
			RandNew();
			if (IsOver())
			{
				status = S_FAIL;
			}
		}
	}

	if (ch == 'Q')
	{
		status = S_QUIT;
	}
	else if (ch == 'R')
	{
		Restart();
	}
}

void Game2048::Draw()
{
	clear();
	const int offset = 12;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			DrawItem(i * 2, 1 + j * WIDTH + offset, '+');

			if (i != N)
			{
				DrawItem(i * 2, 1 + j * WIDTH + offset, '|');
			}

			for (int k = 1; j != N && k < WIDTH; ++k)
			{
				DrawItem(i * 2, 1 + j * WIDTH + k + offset, '-');
			}

			if (i != N && j != N)
			{
				DrawItem(i * 2 + 1, (1 + j) * WIDTH + offset, data[i][j]);
			}
		}
	}
	mvprintw(2 * N + 2, (5 * (N - 4) - 1) / 2, "W(up),S(down),A(left),D(right),R(restart),Q(quit)");
	if (status == S_WIN)
	{
		mvprintw(N, 5 * N / 2 - 1, "You win,press R to continue");
	}
	else if (status == S_FAIL)
	{
		mvprintw(N, 5 * N / 2 - 1, "You lose,press R to continue");
	}
}

void Game2048::SetTestData()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			data[i][j] = 16 << (i + j);
		}
	}
}

bool Game2048::IsOver()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if ((j + 1 < N) && (data[i][j] * data[i][j + 1] == 0 || data[i][j] == data[i][j + 1]))
				return false;
			if ((i + 1 < N) && (data[i][j] * data[i + 1][j] == 0 || data[i][j] == data[i + 1][j]))
				return false;
		}
	}
	return true;
}

bool Game2048::MoveLeft()
{
	int tmp[N][N];
	for (int i = 0; i < N; ++i)
	{             
		int currentWritePos = 0;
		int lastValue = 0;
		for (int j = 0; j < N; ++j)
		{
			tmp[i][j] = data[i][j];
			if (data[i][j] == 0)
			{
				continue;
			}
			if (lastValue == 0)
			{
				lastValue = data[i][j];
			}
			else
			{
				if (lastValue == data[i][j])
				{
					data[i][currentWritePos] = lastValue * 2;
					lastValue = 0;
					if (data[i][currentWritePos] == TARGET)
					{
						status = S_WIN;
					}
				}
				else
				{
					data[i][currentWritePos] = lastValue;
					lastValue = data[i][j];
				}
				++currentWritePos;
			}
			data[i][j] = 0;
		}
		if (lastValue != 0)
		{
			data[i][currentWritePos] = lastValue;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (data[i][j] != tmp[i][j])
				return true;
		}
	}
	return false;
}

void Game2048::Rotate()
{
	int tmp[N][N] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			tmp[i][j] = data[j][N - 1 - i];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			data[i][j] = tmp[i][j];
		}
	}
}

void Game2048::Restart()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			data[i][j] = 0;
		}
	}
	RandNew();
	RandNew();
	status = S_NORMAL;
}

bool Game2048::RandNew()
{
	vector<int> emptyPos;        
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (data[i][j] == 0)
			{
				emptyPos.push_back(i * N + j);
			}
		}
	}
	if (emptyPos.size() == 0)
	{
		return false;
	}     
	int value = emptyPos[rand() % emptyPos.size()];        
	data[value / N][value % N] = rand() % 10 == 1 ? 4 : 2;
	return true;
}

void Game2048::DrawItem(int row, int col, char c)
{
	move(row, col);
	addch(c);
}

void Game2048::DrawNum(int row, int col, int num)
{
	while (num > 0)
	{
		DrawItem(row, col, num % 10 + '0');
		num /= 10;
		--col;
	}
}
