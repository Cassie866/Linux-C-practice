#include "game2048.cpp"

void initialize()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	srand(time(NULL));
}

void shutdown()
{
	endwin();
}

int main()
{
	initialize();
	Game2048 game;
	do
	{
		game.Draw();
		game.ProcessInput();
	} while (S_QUIT != game.GetStatus());

	shutdown();
	return 0;
}
