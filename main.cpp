#include <curses.h>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include "include/row.hpp"
#include "include/draw_helper.hpp"
#include "include/meta.hpp"

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 40
#define MAX_ROWS 10

WINDOW *mainwindow;

std::vector<Row> rows(MAX_ROWS, Row(WINDOW_WIDTH, 0));

int main()
{
	if ((mainwindow = initscr()) == NULL)
	{
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}

	cbreak();
	noecho();
	timeout(50);
	clear();

	draw_centered_string(WINDOW_WIDTH / 2, 2, "Stacker!");
	std::stringstream fmt;
	fmt << "Version " << VERSION;
	draw_centered_string(WINDOW_WIDTH / 2, 3, fmt.str());
	draw_border(WINDOW_WIDTH, WINDOW_HEIGHT, '#');

	refresh();

	while(true){
		char c = getch();
		if (c == 'q')
			break;

		// row.step();
		// row.draw(1, 10);
	}

	endwin();
	return 0;
}