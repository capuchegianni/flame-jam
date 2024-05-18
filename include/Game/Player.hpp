/*
** EPITECH PROJECT, 2024
** flame-jam
** File description:
** Player.hpp
*/

#pragma once

#include "Game.hpp"

class Player : public Game {
    public:
        std::pair<float, float> getPlayerPos() { return _pos; };

    protected:
        std::pair<float, float> _pos = { 900.0, 500.0 };
        int _health = 1;
        std::string _username;
        int _score = 0;
        bool _dash = true;
};
