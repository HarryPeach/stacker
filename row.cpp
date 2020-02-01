#include <utility>
#include "include/row.hpp"

void Row::draw(int x, int y){
	for (int i = 0; i < boxes.size(); i++){
		if(boxes.at(i))
			mvaddch(y, x + i, '@');
		else
			mvaddch(y, x + i, '_');
	}
}

void Row::step(){
	// If direction is true, the block is moving right, otherwise left
	
	if(boxes.at(0)){ // If the block is touching the left wall, move right
		direction = true;
	}else if(boxes.at(boxes.size() - 1)){ // If the block is touching the right wall, move left
		direction = false;
	}

	if(direction){
		// Search for the leftmost part of the block, then shift it right
		for(int i = 0; i <= boxes.size() - 1; i++){
			if(boxes.at(i)){
				boxes.at(i) = false;
				boxes.at(i + blockWidth) = true;
				return;
			}
		}
	}else{
		// Search for the leftmost part of the block, then shift it left
		for(int i = 0; i <= boxes.size() - 1; i++){
			if(boxes.at(i)){
				boxes.at(i - 1) = true;
				boxes.at(i + blockWidth - 1) = false;
				return;
			}
		}
	}
}

std::pair<int, int> Row::test_overlay(Row &beneathRow){
	return std::pair<int, int> (0, 0);
}