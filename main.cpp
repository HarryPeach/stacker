#include <curses.h>
#include <sstream>
#include <thread>
#include <vector>
#include "include/row.hpp"
#include "include/draw_helper.hpp"
#include "include/meta.hpp"

#define WINDOW_WIDTH 30
#define WINDOW_HEIGHT 20
#define MAX_ROWS 15
#define INIT_BLOCK_WIDTH 8

WINDOW *mainwindow;

std::vector<Row> rows(MAX_ROWS, Row(WINDOW_WIDTH, 0));
int currentRow = 0;
int delay = 50;

int main()
{
	if ((mainwindow = initscr()) == NULL)
	{
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}

	cbreak();
	noecho();
	timeout(delay);
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
			if(currentRow == MAX_ROWS - 1){
				std::stringstream fmt;
					fmt << "You won! Final score: " << currentRow + 1;
					draw_centered_string(WINDOW_WIDTH / 2, 4, fmt.str().c_str());
					break;
			}else if(currentRow == 0){
				rows.at(currentRow + 1).setBlockWidth(rows.at(currentRow).getBlockWidth());
				currentRow++;
			}else{
				std::pair<int, int> infoPair = rows.at(currentRow).test_overlay(rows.at(currentRow - 1));
				if(infoPair.first == -1){
					std::stringstream fmt;
					fmt << "You lost! Final score: " << currentRow + 1;
					draw_centered_string(WINDOW_WIDTH / 2, 4, fmt.str().c_str());
					break;
				}
				rows.at(currentRow).setBlockWidth(infoPair.second);
				rows.at(currentRow).moveBlock(infoPair.first);
				rows.at(currentRow + 1).setBlockWidth(rows.at(currentRow).getBlockWidth());
				currentRow++;
			}
			
		}

		rows.at(currentRow).step();
		draw_rows(1, WINDOW_HEIGHT, rows);
	}

	timeout(-1);
	getch();

	endwin();
	return 0;
}