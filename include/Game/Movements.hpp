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
        float playerJump();
        float playerDash();
        float playerMoveLeft();
        float playerMoveRight();
};
