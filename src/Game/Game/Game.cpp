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
        loadAssetsGame("assets/Game/tutoMap.png", "tuto");
        loadAssetsGame("assets/Game/tutoMapHitbox.png", "collisionMap");
        loadAssetsMenu("assets/Menu/fire.png", "fireBerry1");
        loadAssetsMenu("assets/Menu/fire.png", "fireBerry2");
        loadAssetsMenu("assets/Menu/fire.png", "fireBerry3");
        loadAssetsMenu("assets/Menu/fire.png", "fireBerry4");
        loadAssetsMenu("assets/Menu/fire.png", "fireBerry5");
        loadAssetsMenu("assets/Menu/fire.png", "fireBerry6");
        _sprites["player"].setPosition(100, _groundHigh);
        _sprites["player"].setScale(1.8, 1.8);
        _sprites["tuto"].setScale(2, 1.58);
        _sprites["tuto"].setPosition(0, 0);
        _sprites["collisionMap"].setScale(2, 1.58);
        _sprites["fireBerry1"].setPosition(500, 750);
        _sprites["fireBerry1"].setScale(0.3, 0.3);
        _sprites["fireBerry2"].setPosition(1100, 550);
        _sprites["fireBerry2"].setScale(0.3, 0.3);
        _sprites["fireBerry3"].setPosition(1200, 560);
        _sprites["fireBerry3"].setScale(0.3, 0.3);
        _sprites["fireBerry4"].setPosition(1300, 570);
        _sprites["fireBerry4"].setScale(0.3, 0.3);
        _sprites["fireBerry5"].setPosition(1400, 580);
        _sprites["fireBerry5"].setScale(0.3, 0.3);
        _sprites["fireBerry6"].setPosition(1500, 590);
        _sprites["fireBerry6"].setScale(0.3, 0.3);
    }
}

void Game::checkFireBerryCollision()
{
    sf::FloatRect playerBounds = _sprites["player"].getGlobalBounds();

    std::vector<std::string> fireBerries = {"fireBerry1", "fireBerry2", "fireBerry3", "fireBerry4", "fireBerry5", "fireBerry6"};

    for (const auto& fireBerry : fireBerries) {
        if (_sprites.count(fireBerry) > 0 && playerBounds.intersects(_sprites[fireBerry].getGlobalBounds())) {
            _sprites.erase(fireBerry);
            _score += 100;
            break;
        }
    }
}

void Game::animateFireBerry()
{
    if (_animationClock.getElapsedTime().asSeconds() > 1.f / 12.f) {
        _frameNbr++;
        _frameNbr %= 12;

        int row = _frameNbr / 6;
        int col = _frameNbr % 6;

        _sprites["fireBerry1"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _sprites["fireBerry2"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _sprites["fireBerry3"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _sprites["fireBerry4"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _sprites["fireBerry5"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _sprites["fireBerry6"].setTextureRect(sf::IntRect(col * 1240 / 6, row * 425 / 2, 1240 / 6, 410 / 2));
        _animationClock.restart();
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

    checkFireBerryCollision();
    sf::Vector2f oldPos = _sprites["player"].getPosition();
    _sprites["player"].move(_velocity * deltaTime);
    sf::Vector2f newPos = _sprites["player"].getPosition();
    sf::Vector2f scaledPos = sf::Vector2f((newPos.x + 80) / static_cast<float>(_sprites["collisionMap"].getScale().x), (newPos.y + _sprites["player"].getGlobalBounds().height) / static_cast<float>(_sprites["collisionMap"].getScale().y));
    if (scaledPos.x >= 0 && scaledPos.x < _textures["collisionMap"].getSize().x && scaledPos.y >= 0 && scaledPos.y < _textures["collisionMap"].getSize().y) {
        sf::Color pixel = _textures["collisionMap"].copyToImage().getPixel(scaledPos.x, scaledPos.y);
        if (pixel.r == 255 && pixel.g == 0 && pixel.b == 0) {
            _sprites["player"].setPosition(oldPos);
            _velocity.y = 0;
            _isJumping = false;
        }
    }
    if (_dashCooldown > 0)
        _dashCooldown -= deltaTime;
    if (_isDashing) {
        _velocity.x *= 1.2;
        _dashDistance += std::abs(newPos.x - oldPos.x);
        if (_dashDistance >= 300.0f) {
            _isDashing = false;
            _velocity.x = _isMovingRight ? _moveSpeed : -_moveSpeed;
        }
    }
    if (_sprites["player"].getPosition().y >= _groundHigh) {
        _isJumping = false;
        _velocity.y = 0;
        _sprites["player"].setPosition(_sprites["player"].getPosition().x, _groundHigh + 10);
    }
}

void Game::displayScore()
{
    sf::Font font;
    sf::Text text;

    font.loadFromFile("assets/fonts/press.ttf");
    text.setFont(font);
    text.setString("Score: " + std::to_string(_score));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(50, 0);
    _window.draw(text);
}

void Game::drawGame()
{
    _window.clear();
    if (_isReset == false) {
        _sprites.clear();
        _textures.clear();
        _isReset = true;
    }
    animateFireBerry();
    setUpGraphicsGame();
    drawAssetsGame();
    displayScore();
    float deltaTime = _clock.restart().asSeconds();
    updatePlayerPos(deltaTime);
}
