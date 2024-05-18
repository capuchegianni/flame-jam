/*
** EPITECH PROJECT, 2024
** flame-jam
** File description:
** Movements.cpp
*/
#include "../../../include/Game/Movements.hpp"

float Movements::playerMoveLeft()
{
    return _pos.first -= 200.0;
}

float Movements::playerMoveRight()
{
    return _pos.first += 200.0;
}

float Movements::playerJump()
{
    return _pos.second += 1500.0;
}

float Movements::playerDash()
{
    if (_event.type == sf::Event::KeyPressed) {
        if (_event.key.code == sf::Keyboard::Q) {
            return _pos.first -= 10;
        }
        if (_event.key.code == sf::Keyboard::D) {
            return _pos.first += 10;
        }
    }
    return 0.0;
}
