#pragma once
#include <string> 
#include <vector> 
#include <cstdlib> 
#include <cstdio> 
#include <ctime> 
#include <curses.h> 
using namespace std;

#define N 4  
#define WIDTH 5 
#define TARGET 2048 
#define S_FAIL 0 
#define S_WIN 1 
#define S_NORMAL 2 
#define S_QUIT 3

class Game2048
{
public:
	Game2048();
	int GetStatus();
	void ProcessInput();
	void Draw();
	void SetTestData();
private:
	bool IsOver();
	bool MoveLeft();
	void Rotate();
	void Restart();
	bool RandNew();
	void DrawItem(int row, int col, char c);
	void DrawNum(int row, int col, int num);
private:
	int data[N][N];
	int status;
};
