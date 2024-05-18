/*
** EPITECH PROJECT, 2024
** flame-jam
** File description:
** Movements.hpp
*/

#pragma once

#include <unordered_map>
#include "../Enum/Input.hpp"
#include "Player.hpp"

class Movements : public Player {
    public:
        void playerJump();
        void playerDash();
        void playerMoveLeft();
        void playerMoveRight();
        void parseKeyboard();
};