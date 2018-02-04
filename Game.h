#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <SFML/Graphics.hpp>

namespace Minesweeper{

class Game{
public:
    Game();
    Game(unsigned int rows, unsigned int colons, unsigned int mines);
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
    sf::Font font;
    sf::Text text;
};

}

#endif // GAME_H
