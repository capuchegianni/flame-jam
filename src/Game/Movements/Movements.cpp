/*
** EPITECH PROJECT, 2024
** flame-jam
** File description:
** Movements.cpp
*/
#include "../../../include/Game/Movements.hpp"

void Movements::playerMoveLeft()
{
    _pos.first -= 2;
}

void Movements::playerMoveRight()
{
    _pos.first += 2;
}

void Movements::playerJump()
{
    _pos.second += 15;
}

void Movements::playerDash()
{
    if (_event.type == sf::Event::KeyPressed) {
        if (_event.key.code == sf::Keyboard::Q) {
            _pos.first -= 10;
        }
        if (_event.key.code == sf::Keyboard::D) {
            _pos.first += 10;
        }
    }
}

void Movements::parseKeyboard(Input)
{
    if (_event.type == sf::Event::KeyPressed) {
        if (_event.key.code == sf::Keyboard::Q) {
            playerMoveLeft();
        }
        if (_event.key.code == sf::Keyboard::D) {
            playerMoveRight();
        }
        if (_event.key.code == sf::Keyboard::Space) {
            playerJump();
        }
        if (_event.key.code == sf::Keyboard::P) {
            playerDash();
        }
    }
}