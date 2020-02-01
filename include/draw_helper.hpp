#include <string>
#include <ncurses.h>

/**
 * Draws a border of a specific width and height, using a given character.
 * @param width the width of the border
 * @param height the height of the border
 * @param border_char the character that should be used to draw the border
 **/
void draw_border(int width, int height, char border_char);

/**
 * Draws a centered string to the screen
 * @param x the x coordinate of the center of the string
 * @param y the y coordinate of the string
 * @param text the text to be drawn
 **/
void draw_centered_string(int x, int y, std::string text);