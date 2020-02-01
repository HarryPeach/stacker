#include <curses.h>
#include <iostream>
#include "draw_helper.hpp"

WINDOW* mainwindow;

int main(){
	if ((mainwindow = initscr()) == NULL){
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}

	cbreak();
	noecho();
	clear();

	mvaddstr(2, 2, "Stacker!");
	draw_border(40, 30, '#');

	refresh();

	getch();
	endwin();
	return 0;
}