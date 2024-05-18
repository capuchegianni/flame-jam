/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Game
*/

#include "../../include/Game/Game.hpp"

void Game::drawAssets()
{
    for (auto &sprite : _sprites) {
        _window.draw(sprite.second);
    }
}

void Game::loadAssets(std::string path, std::string name)
{
    _textures[name].loadFromFile(path);
    _sprites[name].setTexture(_textures[name]);

    if (name == "fireUpLeft") {
        _sprites[name].setTextureRect(sf::IntRect(0, 0, 1280 / 6, 425 / 2));
        _sprites[name].setPosition(0, 0);
    }
    if (name == "fireUpRight") {
        _sprites[name].setTextureRect(sf::IntRect(0, 0, 1280 / 6, 425 / 2));
        _sprites[name].setPosition(1700, 0);
    }
}

void Game::setUpGraphics()
{
    _window.create(sf::VideoMode(1920, 1080), "SFML window");
    loadAssets("assets/Menu/fire.png", "fireUpLeft");
    loadAssets("assets/Menu/fire.png", "fireUpRight");
}

void Game::animateFire()
{
    if (_animationClock.getElapsedTime().asSeconds() > 1.f / 12.f) {
        _frameNbr++;
        _frameNbr %= 12;

        int row = _frameNbr / 6;
        int col = _frameNbr % 6;

        _sprites["fireUpLeft"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _sprites["fireUpRight"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _animationClock.restart();
    }
}

void Game::run()
{
    setUpGraphics();
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        animateFire();
        drawAssets();
        _window.display();
    }
}
