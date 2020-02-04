#include <utility>
#include <iostream>
#include "include/row.hpp"

void Row::draw(int x, int y){
	for (int i = 0; i < boxes.size(); i++){
		if(boxes.at(i))
			mvaddch(y, x + i, '@');
		else
			mvaddch(y, x + i, ' ');
	}
}

void Row::step(){
	// If direction is true, the block is moving right, otherwise left
	
	if(blockStart == 0){
		direction = true;
	}else if (blockEnd == boxes.size() - 1){
		direction = false;
	}


	if(direction){
		boxes.at(blockStart) = false;
		boxes.at(blockEnd + 1) = true;
		blockStart++;
		blockEnd++;
	}else{
		boxes.at(blockEnd) = false;
		boxes.at(blockStart - 1) = true;
		blockStart--;
		blockEnd--;
	}
}

std::pair<int, int> Row::test_overlay(Row &beneathRow){
	int blockStartPos = -1;
	int blockLength = 0;

	for (int i = blockStart; i <= blockEnd; i++){
		if(blockStartPos == -1){
			if(beneathRow.getBoxes().at(i)){
				blockStartPos = i;
			}
		}

		if(beneathRow.getBoxes().at(i)){
			blockLength++;
		}
	}
	return std::pair<int, int> (blockStartPos, blockLength);
}