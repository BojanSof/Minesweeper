#include "Random.h"

Minesweeper::Random::Random(){
#ifdef __WIN32
engine.seed(time(NULL));
#else
engine.seed(std::random_device()());
#endif
}

Minesweeper::Random::~Random() {}

int Minesweeper::Random::randInt(int low, int high){
    std::uniform_int_distribution<int> dist(low, high);
    return dist(engine);
}

unsigned int Minesweeper::Random::randUInt(unsigned int low, unsigned int high){
    std::uniform_int_distribution<unsigned int> dist(low, high);
    return dist(engine);
}
