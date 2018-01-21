#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include "Random.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

namespace Minesweeper{

class Grid{
friend class Game;
public:
    Grid();
    Grid(unsigned int r, unsigned int c, unsigned int m);
    ~Grid();
    void generateGrid();
    void printGrid();
    void showGrid();
    void revealAdjacents(unsigned int x, unsigned int y);
    unsigned int getRows();
    unsigned int getCols();
    unsigned int getMines();
    std::vector<std::vector<Cell>>& getGrid();
    std::vector<std::vector<unsigned int>>& getSGrid();
private:
    unsigned int rows;
    unsigned int cols;
    unsigned int mines;
    std::vector<std::vector<Cell>> grid;
    std::vector<std::vector<unsigned int>> sgrid;
    Random rng;
};

}

#endif // GRID_H
