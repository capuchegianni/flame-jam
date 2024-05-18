/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** main
*/

#include "../include/Game/Game.hpp"

int main(void)
{
    try {
        Game game;
        game.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
