#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <random>

namespace Minesweeper{

class Random{
public:
    Random();
    ~Random();
    int randInt(int low, int high);
    unsigned int randUInt(unsigned int low, unsigned int high);
private:
    std::mt19937 engine;
};

}

#endif // RANDOM_H
