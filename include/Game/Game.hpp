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
        void blinkText();

        void drawGame();
        void catchInputGame(Input input);
        void setUpGraphicsGame();
        void loadAssetsGame(std::string path, std::string name);
        void drawAssetsGame();
        GameStatus catchEvents();
        void updateWindow();

        void updatePlayerPos(float deltaTime);
        void animateJump(float deltaTime);
        void animateRun();
        void animateIdle();

    private:
        sf::RenderWindow _window;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _sprites;
        int _frameNbr = 0;
        sf::Clock _animationClock;
        sf::Clock _blinkClock;
        GameStatus _gameStatus = MENU;
        Input _input;
        bool _isReset = false;
        sf::Vector2f _velocity = { 0, 0 };
        float _gravity = 1300.0f;
        float _jumpSpeed = 600.0f;
        sf::Clock _clock;
        bool _isJumping = false;
        int _groundHigh = 600;
        int _moveSpeed = 200;
        int _currentFrame = 0;
        int _updatesSinceLastFrame = 0;
        bool _isMovingRight = false;
        bool _isInit = false;

    protected:
        sf::Event _event;
};
