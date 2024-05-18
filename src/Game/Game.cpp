/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Game
*/

#include "../../include/Game/Game.hpp"

Input Game::catchInput()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Z)
                return UP;
            if (_event.key.code == sf::Keyboard::S)
                return DOWN;
            if (_event.key.code == sf::Keyboard::Q)
                return LEFT;
            if (_event.key.code == sf::Keyboard::D)
                return RIGHT;
        }
    }
    return NONE;
}

void Game::run()
{
    setUpGraphicsMenu();
    while (_window.isOpen()) {
        _gameStatus = catchEvents();
        _input = catchInput();
        if (_gameStatus == MENU) {
            catchInputMenu(_input);
            drawMenu();
        }
        else if (_gameStatus == GAME)
            drawGame();
        else if (_gameStatus == EXIT)
            _window.close();
        _window.display();
    }
}
