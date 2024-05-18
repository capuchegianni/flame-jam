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
    loadAssetsGame("assets/Game/charSpriteSheet.png", "player");
    if (_isInit == false) {
        _isInit = true;
        _sprites["player"].setPosition(100, _groundHigh);
        _sprites["player"].setScale(1.5, 1.5);
    }
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
                _currentFrame = 0;
            }
            break;
        case RIGHT:
            if (!_isMovingRight) {
                _isMovingRight = true;
                _currentFrame = 0;
            }
            _velocity.x = _moveSpeed;
            break;
        case LEFT:
            if (_isMovingRight) {
                _isMovingRight = false;
                _currentFrame = 0;
            }
            _velocity.x = -_moveSpeed;
            break;
        case DASH:
            if (!_isDashing && _dashCooldown <= 0) {
                _isDashing = true;
                _dashDistance = 0.0f;
                _dashCooldown = _DASH_COOLDOWN_TIME;
            }
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

void Game::animateJump(float deltaTime)
{
    _velocity.y += _gravity * deltaTime;
    int frameWidth = 832 / 13;
    int frameHeight = 2944 / 46;
    int row = _isMovingRight ? 29 : 27;
    _sprites["player"].setTextureRect(sf::IntRect(_currentFrame * frameWidth, row * frameHeight, frameWidth, frameHeight));
    _updatesSinceLastFrame++;
    if (_updatesSinceLastFrame >= 5) {
        if (_currentFrame < 4)
            _currentFrame++;
        _updatesSinceLastFrame = 0;
    }
}

void Game::animateRun()
{
    int frameWidth = 832 / 13;
    int frameHeight = 2944 / 46;
    int row = _isMovingRight ? 37 : 35;
    _sprites["player"].setTextureRect(sf::IntRect((_currentFrame % 8) * frameWidth, row * frameHeight, frameWidth, frameHeight));
    _updatesSinceLastFrame++;
    if (_updatesSinceLastFrame >= 5) {
        _currentFrame++;
        _updatesSinceLastFrame = 0;
    }
}

void Game::animateIdle()
{
    int frameWidth = 832 / 13;
    int frameHeight = 2944 / 46;
    int row = 6;
    _sprites["player"].setTextureRect(sf::IntRect(0 * frameWidth, row * frameHeight, frameWidth, frameHeight));
}

void Game::updatePlayerPos(float deltaTime)
{
    if (_isJumping)
        animateJump(deltaTime);
    else if (_velocity.x != 0)
        animateRun();
    else
        animateIdle();

    sf::Vector2f oldPos = _sprites["player"].getPosition();
    _sprites["player"].move(_velocity * deltaTime);
    sf::Vector2f newPos = _sprites["player"].getPosition();
    if (_dashCooldown > 0)
        _dashCooldown -= deltaTime;
    if (_isDashing) {
        _velocity.x *= 1.2;
        _dashDistance += std::abs(newPos.x - oldPos.x);
        if (_dashDistance >= 200.0f) {
            _isDashing = false;
            _velocity.x = _isMovingRight ? _moveSpeed : -_moveSpeed;
        }
    }
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
