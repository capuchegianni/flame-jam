/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Game
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Enum/Input.hpp"

class Game {
    public:
        Game() = default;
        ~Game() = default;
        void run();
        void setUpGraphics();
        void loadAssets(std::string path, std::string name);
        void drawAssets();
        void animateFire();

    private:
        sf::RenderWindow _window;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _sprites;
        int _frameNbr = 0;
        sf::Clock _animationClock;

    protected:
        sf::Event _event;
};
