#include <vector>
#include <curses.h>

class Row {
	private:
		int rowWidth;
		int blockWidth;
		std::vector<bool> boxes;
	public:
		Row(int rWidth, int bWidth){
			rowWidth = rWidth;
			blockWidth = bWidth;
			boxes.resize(rowWidth);
			for (int i = 0; i < blockWidth; i++){
				boxes.push_back(true);
			}
		}

		int getBlockWidth(){
			return blockWidth;
		}

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