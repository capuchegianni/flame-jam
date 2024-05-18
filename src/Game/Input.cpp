/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Input
*/

#include "../../include/Game/Game.hpp"

GameStatus Game::catchEvents()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return EXIT;
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Enter)
                return GAME;
        }
    }
    return _gameStatus;
}
