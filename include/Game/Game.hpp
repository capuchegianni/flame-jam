/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Enum/GameStatus.hpp"
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
        sf::Event _event;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _sprites;
        int _frameNbr = 0;
        sf::Clock _animationClock;
        GameStatus _gameStatus = MENU;
        Input _input;
};

#endif /* !GAME_HPP_ */
