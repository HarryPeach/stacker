#include <curses.h>
#include <iostream>
#include <sstream>
#include "draw_helper.hpp"
#include "meta.hpp"

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 40

WINDOW *mainwindow;

int main()
{
	if ((mainwindow = initscr()) == NULL)
	{
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}

	cbreak();
	noecho();
	clear();

	draw_centered_string(WINDOW_WIDTH / 2, 2, "Stacker!");
	std::stringstream fmt;
	fmt << "Version " << VERSION;
	draw_centered_string(WINDOW_WIDTH / 2, 3, fmt.str());
	draw_border(WINDOW_WIDTH, WINDOW_HEIGHT, '#');

	refresh();

	getch();

	endwin();
	return 0;
}