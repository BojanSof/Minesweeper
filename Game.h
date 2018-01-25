#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <SFML/Graphics.hpp>

namespace Minesweeper{

class Game{
public:
    Game();
    ~Game();
    void Run();
    void Test();
private:
    void checkEvents();
    void checkWinState();
    
    bool end;
    unsigned int height;
    unsigned int width;
    Grid grid;
    sf::RenderWindow window;
    sf::Texture tiles;
    sf::Sprite sprite;
};

}

#endif // GAME_H
