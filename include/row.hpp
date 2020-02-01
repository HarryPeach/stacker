#ifndef ROW_H
#define ROW_H
#include <vector>
#include <utility>
#include <curses.h>
/**
 * This class represents a row within the Stacker game.
 * Each row is a single line of a specific length, which has a block that moves back and forth along the row.
 * The aim of the game is to stack these blocks as precisely as possible.
 **/
class Row {
	private:
		int rowWidth;
		int blockWidth;
		int blockStart;
		int blockEnd;
		int direction = false;
		std::vector<bool> boxes;
	public:
		/**
		 * @param rWidth the initial width of the row
		 * @param bWidth the initial width of the block
		 **/
		Row(int rWidth, int bWidth){
			rowWidth = rWidth;
			blockWidth = bWidth;
			boxes.resize(rowWidth);
			for (int i = blockWidth; i != 0; i--){
				boxes.at(i) = true;
			}
			blockStart = 0;
			blockEnd = blockWidth - 1;
		}

		Row(const Row &row){
			rowWidth = row.rowWidth;
			boxes.resize(rowWidth);
			blockWidth = 0;
		}

		/**
		 * Returns the width of the block
		 **/
		int getBlockWidth(){
			return blockWidth;
		}

		/**
		 * Returns the width of the row
		 **/
		int getRowWidth(){
			return rowWidth;
		}

		/**
		 * Sets the width of a block
		 * @param int the width of the block
		 **/
		void setBlockWidth(int width){
			blockWidth = width;
			for (int i = blockWidth - 1; i != -1; i--){
				boxes.at(i) = true;
			}
			blockStart = 0;
			blockEnd = blockWidth - 1;
		}

		/**
		 * Moves the block along one step, "bouncing" off of each wall
		 **/
		void step();

		/**
		 * Draws the entire row to the screen at a given set of coordinates
		 * @param x the x coordinate
		 * @param y the y coordinate
		 **/
		void draw(int x, int y);

		/**
		 * Checks whether the current block is above the block in the row beneath
		 * @param beneathRow the row beneath the current row
		 * @return A pair of ints, the first being where the block should stop, the second being the length of the block after the check.
		 * 		   Both integers will be -1 if the block missed the beneath block.
		 **/  
		std::pair<int, int> test_overlay(Row &beneathRow);
};
#endif // ROW_H