/*
** EPITECH PROJECT, 2024
** flame-jam
** File description:
** Movements.cpp
*/
#include "../../../include/Game/Movements.hpp"

std::unordered_map<sf::Keyboard::Key, Input> keymap = {
    {sf::Keyboard::Escape, ESCAPE},
    {sf::Keyboard::Q, LEFT},
    {sf::Keyboard::D, RIGHT},
    {sf::Keyboard::Space, JUMP},
    {sf::Keyboard::P, DASH},
};

void Movements::parseKeyboard(Input)
{
    switch (_event) {
        if (sf::Keyboard::Escape)
    }
}

void Movements::playerJump()
{

}