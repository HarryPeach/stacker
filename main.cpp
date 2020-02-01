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
#define INIT_BLOCK_WIDTH 10

WINDOW *mainwindow;

std::vector<Row> rows(MAX_ROWS, Row(WINDOW_WIDTH, 0));
int currentRow = 0;

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

	rows.at(currentRow).setBlockWidth(INIT_BLOCK_WIDTH);
	while(true){
		char c = getch();
		if (c == 'q')
			break;

		if (c == ' '){
			if(currentRow == 0){
				rows.at(currentRow + 1).setBlockWidth(rows.at(currentRow).getBlockWidth());
				currentRow++;
			}
		}

		draw_rows(1, WINDOW_HEIGHT, rows);
		rows.at(currentRow).step();
	}

	endwin();
	return 0;
}