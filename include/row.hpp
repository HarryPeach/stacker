#include <vector>
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
			for (int i = 0; i < blockWidth; i++){
				boxes.push_back(true);
			}
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
		 * Moves the block along one step, "bouncing" off of each wall
		 **/
		void step();

		/**
		 * Draws the entire row to the screen at a given set of coordinates
		 * @param x the x coordinate
		 * @param y the y coordinate
		 **/
		void draw(int x, int y);		
};