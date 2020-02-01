#include <string>
#include <ncurses.h>

void draw_border(int width, int height, char border_char);
void draw_centered_string(int width, int height, std::string text);