#include "Cell.h"
#include <iostream>

Minesweeper::Cell::Cell() : mine(false), value(0) {}

void Minesweeper::Cell::operator++(int postfix){
        if(mine) return;
        value++;
}

std::ostream& Minesweeper::operator<<(std::ostream& outStream, const Minesweeper::Cell& cell){
        if(cell.mine) outStream << "x";
        else outStream << cell.value;
        return outStream;
}
