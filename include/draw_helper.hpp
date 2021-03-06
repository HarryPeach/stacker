#ifndef DRAW_HELPER_H
#define DRAW_HELPER_H
#include <string>
#include <curses.h>
#include <vector>
#include "row.hpp"

/**
 * Draws a border of a specific width and height, using a given character.
 * @param width the width of the space inside the border
 * @param height the height of the space inside the border
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

/**
 * Draws all the rows in a given vector of rows. Rows are drawn from the bottom left, up.
 * @param x The x position to draw rows
 * @param y The y position to draw rows
 * @param rows A reference to a vector containing rows
 **/
void draw_rows(int x, int y, std::vector<Row> &rows);
#endif // DRAW_HELPER_H