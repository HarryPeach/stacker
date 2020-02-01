#include <ncurses.h>

void draw_border(int width, int height, char border_char){
	for (int i = 0; i <= width; i++){
		mvaddch(0, i, border_char);
		mvaddch(height, i, border_char);
	}

	for (int i = 0; i <= height; i++){
		mvaddch(i, 0, border_char);
		mvaddch(i, width, border_char);
		// mvaddch(height, 1, border_char);
		// mvaddch(height, i + 1, border_char);
	}
}