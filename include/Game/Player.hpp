/*
** EPITECH PROJECT, 2024
** flame-jam
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Game.hpp"

class Player public Game{
    public:

    private:
        int _health = 1;
        std::string _username;
        std::pair<float, float> _pos = { 0.0, 0.0};
        int _score = 0;
        bool _dash = true;
};
