#ifndef CELL_H
#define CELL_H

#include <iostream>

namespace Minesweeper{

struct Cell{
    bool mine;
    int value;

    Cell();
    void operator++(int postfix);
};

std::ostream& operator<<(std::ostream& outStream, const Minesweeper::Cell& cell);

}

#endif // CELL_H
