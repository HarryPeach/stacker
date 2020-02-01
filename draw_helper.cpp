#include "include/draw_helper.hpp"

void draw_border(int width, int height, char border_char){
	// Draw the border horizontally
	for (int i = 0; i <= width + 1; i++){
		mvaddch(0, i, border_char);
		mvaddch(height + 1, i, border_char);
	}

	for (int i = 0; i <= height + 1; i++){
		mvaddch(i, 0, border_char);
		mvaddch(i, width + 1, border_char);
	}
}

void draw_centered_string(int x, int y, std::string text){
	mvaddstr(y, x - (text.size() / 2), text.c_str());
}