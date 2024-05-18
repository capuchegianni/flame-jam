/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Game
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Enum/GameStatus.hpp"
#include "../Enum/Input.hpp"
#include <vector>
#include "../Enum/Input.hpp"

class Game {
    public:
        Game() = default;
        ~Game() = default;
        void run();
        Input catchInput();

        void drawMenu();
        void setUpGraphicsMenu();
        void loadAssetsMenu(std::string path, std::string name);
        void drawAssetsMenu();
        void animateFire();
        void catchInputMenu(Input input);
        void drawTitle();

        void drawGame();
        GameStatus catchEvents();

    private:
        sf::RenderWindow _window;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _sprites;
        int _frameNbr = 0;
        sf::Clock _animationClock;
        GameStatus _gameStatus = MENU;
        Input _input;

    protected:
        sf::Event _event;
};
