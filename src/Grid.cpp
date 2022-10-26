#include "Grid.h"

Minesweeper::Grid::Grid() : rows(9), cols(9), mines(10), grid(rows+2, std::vector<Minesweeper::Cell>(cols+2)), sgrid(rows+2, std::vector<unsigned int>(cols+2, 10)), rng(){
    generateGrid();
}

Minesweeper::Grid::Grid(unsigned int r, unsigned int c, unsigned int m)  : rows(r), cols(c), mines(m), grid(rows+2, std::vector<Minesweeper::Cell>(cols+2)), sgrid(rows+2, std::vector<unsigned int>(cols+2, 10)), rng(){
    generateGrid();

}

Minesweeper::Grid::~Grid() {}

void Minesweeper::Grid::generateGrid(){
    unsigned int r;
    for(unsigned int i = 0; i < mines; i++){
        do{
            r = rng.randUInt(0, rows*cols);
        } while(grid[r/cols + 1][r%cols + 1].mine);
        grid[r/cols + 1][r%cols + 1].mine = true;
        grid[r/cols + 1][r%cols + 1].value = 9;
    }
    for(unsigned int i = 1; i <= rows; i++){
        for(unsigned int j = 1; j <= cols; j++){
            if(grid[i][j].mine){
                grid[i-1][j-1]++;
                grid[i-1][j]++;
                grid[i-1][j+1]++;
                grid[i][j-1]++;
                grid[i][j]++;
                grid[i][j+1]++;
                grid[i+1][j-1]++;
                grid[i+1][j]++;
                grid[i+1][j+1]++;
            }
        }
    }
}

void Minesweeper::Grid::printGrid(){
    for(unsigned int i = 1; i <= rows; i++){
        for(unsigned int j = 1; j <= cols; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Minesweeper::Grid::showGrid(){
    for(unsigned int i = 1; i <= rows; i++){
        for(unsigned int j = 1; j <= cols; j++){
            if(grid[i][j].mine) sgrid[i][j] = 9;
            else if(sgrid[i][j] == 11 && grid[i][j].mine) {/*do nothing*/}
            else sgrid[i][j] = grid[i][j].value;
        }
    }
}

void Minesweeper::Grid::revealAdjacents(unsigned int x, unsigned int y){
    unsigned int minx = x <= 1 ? 1 : x - 1;
    unsigned int maxx = x >= rows ? rows : x + 1;
    unsigned int miny = y <= 1 ? 1 : y - 1;
    unsigned int maxy = y >= cols ? cols : y + 1;;

    for(unsigned int i = minx; i <= maxx; i++){
        for(unsigned int j = miny; j <= maxy; j++){
            if(i == x && j == y) continue;
            if(grid[i][j].value == 0 && sgrid[i][j] != 0){
                sgrid[i][j] = grid[i][j].value;
                revealAdjacents(i, j);
            } else if(!grid[i][j].mine){
                sgrid[i][j] = grid[i][j].value;
            }
        }
    }
}

unsigned int Minesweeper::Grid::getRows(){
    return rows;
}

unsigned int Minesweeper::Grid::getCols(){
    return cols;
}

unsigned int Minesweeper::Grid::getMines(){
    return mines;
}

std::vector<std::vector<Minesweeper::Cell>>& Minesweeper::Grid::getGrid(){
    return grid;
}

std::vector<std::vector<unsigned int>>& Minesweeper::Grid::getSGrid(){
    return sgrid;
}
