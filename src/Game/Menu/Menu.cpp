/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Menu
*/

#include "../../../include/Game/Game.hpp"

void Game::drawAssetsMenu()
{
    for (auto &sprite : _sprites) {
        _window.draw(sprite.second);
    }
}

void Game::loadAssetsMenu(std::string path, std::string name)
{
    _textures[name].loadFromFile(path);
    _sprites[name].setTexture(_textures[name]);

    if (name == "background") {
        _sprites[name].setScale(1.11, 1.052);
    }
    if (name == "fireUpLeft") {
        _sprites[name].setTextureRect(sf::IntRect(0, 0, 1280 / 6, 425 / 2));
        _sprites[name].setPosition(0, 0);
    }
    if (name == "fireUpRight") {
        _sprites[name].setTextureRect(sf::IntRect(0, 0, 1280 / 6, 425 / 2));
        _sprites[name].setPosition(1700, 0);
    }
}

void Game::setUpGraphicsMenu()
{
    _window.create(sf::VideoMode(1920, 1080), "SFML window");
    loadAssetsMenu("assets/Menu/background.jpg", "background");
    loadAssetsMenu("assets/Menu/fire.png", "fireUpLeft");
    loadAssetsMenu("assets/Menu/fire.png", "fireUpRight");
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

void Game::blinkText()
{
    sf::Font font;
    sf::Text text;

    font.loadFromFile("assets/fonts/press.ttf");
    text.setFont(font);
    text.setString("Press Enter to start");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(600, 500);

    float time = _blinkClock.getElapsedTime().asSeconds();
    if (time < 0.5f)
        text.setFillColor(sf::Color::Transparent);
    else {
        text.setFillColor(sf::Color::Black);
        if (time > 1.0f)
            _blinkClock.restart();
    }
    _window.draw(text);
}

void Game::catchInputMenu(Input input)
{
    switch (input) {
        case UP:
            std::cout << "UP" << std::endl;
            break;
        case DOWN:
            std::cout << "DOWN" << std::endl;
            break;
        case LEFT:
            std::cout << "LEFT" << std::endl;
            break;
        case RIGHT:
            std::cout << "RIGHT" << std::endl;
            break;
        case ENTER:
            _gameStatus = GAME;
            break;
        default:
            break;
    }
}

void Game::drawTitle()
{
    sf::Font font;
    sf::Text text, text2;

    font.loadFromFile("assets/fonts/JuicyFills.ttf");
    text.setFont(font);
    text.setString("ToufeuTouflam");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text2.setFont(font);
    text2.setString("ToufeuTouflam");
    text2.setCharacterSize(100);
    text2.setFillColor(sf::Color::Black);

    text.setPosition(500, 100);
    text2.setPosition(510, 90);
    _window.draw(text2);
    _window.draw(text);
}

void Game::drawMenu()
{
    animateFire();
    drawAssetsMenu();
    blinkText();
    drawTitle();
}
