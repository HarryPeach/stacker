#include "row.hpp"

void Row::draw(int x, int y){
	for (int i = 0; i < boxes.size(); i++){
		if(boxes.at(i))
			mvaddch(y, x + i, '#');
		else
			mvaddch(y, x + i, '_');
	}
}