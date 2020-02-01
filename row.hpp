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

		void step();
		void draw(int x, int y);		
};