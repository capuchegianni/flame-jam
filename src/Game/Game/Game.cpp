/*
** EPITECH PROJECT, 2024
** toufeutouflam
** File description:
** Game
*/

#include "../../../include/Game/Game.hpp"
#include "../../../include/Game/Movements.hpp"

void Game::drawAssetsGame()
{
    for (auto &sprite : _sprites) {
        _window.draw(sprite.second);
    }
}

void Game::loadAssetsGame(std::string path, std::string name)
{
    _textures[name].loadFromFile(path);
    _sprites[name].setTexture(_textures[name]);
}

void Game::setUpGraphicsGame()
{
    loadAssetsGame("assets/Menu/menuButton.png", "player");
}

void Game::updateWindow()
{
    _window.display();
}

void Game::catchInputGame(Input input)
{
    switch (input) {
        case JUMP:
            if (_velocity.y == 0) {
                _velocity.y = -_jumpSpeed;
                _isJumping = true;
            }
            break;
        case RIGHT:
            _velocity.x = _moveSpeed;
            break;
        case LEFT:
            _velocity.x = -_moveSpeed;
            break;
        case DASH:
            break;
        case RELEASE_R:
            _velocity.x = 0;
            break;
        case RELEASE_L:
            _velocity.x = 0;
            break;
        default:
            break;
    }
}

void Game::updatePlayerPos(float deltaTime)
{
    if (_isJumping) {
        _velocity.y += _gravity * deltaTime;
    }
    _sprites["player"].move(_velocity * deltaTime);
    if (_sprites["player"].getPosition().y >= _groundHigh) {
        _isJumping = false;
        _velocity.y = 0;
        _sprites["player"].setPosition(_sprites["player"].getPosition().x, _groundHigh);
    }
}

void Game::drawGame()
{
    _window.clear();
    if (_isReset == false) {
        _sprites.clear();
        _textures.clear();
        _isReset = true;
    }
    setUpGraphicsGame();
    drawAssetsGame();
    float deltaTime = _clock.restart().asSeconds();
    updatePlayerPos(deltaTime);
}
