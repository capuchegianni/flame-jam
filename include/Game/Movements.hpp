/*
** EPITECH PROJECT, 2024
** flame-jam
** File description:
** Movements.hpp
*/
#include "Player.hpp"
#include <unordered_map>
#include "../Enum/Input.hpp"

#pragma once

class Movements : public Player{
    public:
        void playerJump();
        void playerDash();
        void playerMoveLeft();
        void playerMoveRight();
        void parseKeyboard(Input);
};