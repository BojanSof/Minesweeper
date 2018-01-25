#include "Game.h"
#include <cmath>

Minesweeper::Game::Game() : end(false), height(288), width(288), grid(), window(sf::VideoMode(width, height), "Minesweeper", sf::Style::Close){
    tiles.loadFromFile("images/tiles.png");
    sprite.setTexture(tiles);
}

Minesweeper::Game::~Game() {}

void Minesweeper::Game::checkEvents(){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    unsigned int x = mousePos.x/32 + 1;
    unsigned int y = mousePos.y/32 + 1;
    sf::Event e;
    while(window.pollEvent(e)){
        if(e.type == sf::Event::Closed)
            window.close();
        if(!end){
            if(e.type == sf::Event::MouseButtonReleased){
                if(e.mouseButton.button == sf::Mouse::Left){
                    if(grid.grid[x][y].value == 0){
                        //reveal all adjacent white cells and theirs adjacent's too
                        grid.sgrid[x][y] = grid.grid[x][y].value;
                        grid.revealAdjacents(x,y);
                    }
                    else if(grid.grid[x][y].mine){
                        std::cout << "You lost!" << std::endl;
                        grid.showGrid();
                        end = true;
                    }
                    else if(grid.sgrid[x][y] != 10) {/*do nothing*/}
                    else grid.sgrid[x][y] = grid.grid[x][y].value;
                }
                else if(e.mouseButton.button  == sf::Mouse::Right){
                    if(grid.sgrid[x][y] >= 0 && grid.sgrid[x][y] <= 8) {/*do nothing*/}
                    else if(grid.sgrid[x][y] == 11) grid.sgrid[x][y] = 10;
                    else grid.sgrid[x][y] = 11;
                }
            }
        }
    }
}

void Minesweeper::Game::checkWinState(){
    if(!end){
        for(unsigned int i = 1; i <= grid.getRows(); i++){
            for(unsigned int j = 1; j <= grid.getCols(); j++){
                if(grid.grid[i][j].value == 9 && grid.sgrid[i][j] == 11) continue;
                if(grid.grid[i][j].value != grid.sgrid[i][j]) return;
            }
        }
        std::cout << "You won!" << std::endl;
        end = true;
    }
}

void Minesweeper::Game::Run(){
    while(window.isOpen()){
        checkEvents();

        window.clear(sf::Color::White);
        for(unsigned int i = 1; i <= grid.getRows(); i++){
            for(unsigned int j = 1; j <= grid.getCols(); j++){

                sprite.setTextureRect(sf::IntRect(grid.sgrid[i][j] * 32,0,32,32));
                sprite.setPosition((i-1)*32, (j-1)*32);
                window.draw(sprite);
            }
        }
        window.display();
        checkWinState();
    }
}

void Minesweeper::Game::Test(){
    while(window.isOpen()){
        checkEvents();

        window.clear(sf::Color::White);
        sprite.setPosition(0, 0);
        window.draw(sprite);
        window.display();

    }
}
