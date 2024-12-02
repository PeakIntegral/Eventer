#include "Creature.h"

// Скорость движения, пикселей в секунду.
const float CREATURE_SPEED = 60.f;

// Радиус фигурки в пикселях.
const float CREATURE_RADIUS = 20.f;

// RGB-цвет заливки фигурки/
const sf::Color CREATURE_COLOR = sf::Color(100, 255, 85);

Creature::Creature() {
    this->direction = Direction::NONE;
    this->shape.setRadius(CREATURE_RADIUS);
    this->shape.setFillColor(CREATURE_COLOR);
}

void Creature::updateCreature(float elapsedTime)
{
    const float step = CREATURE_SPEED * elapsedTime;
    sf::Vector2f position = this->shape.getPosition();
    switch (this->direction)
    {
    case Direction::UP:
        position.y -= step;
        break;
    case Direction::DOWN:
        position.y += step;
        break;
    case Direction::LEFT:
        position.x -= step;
        break;
    case Direction::RIGHT:
        position.x += step;
        break;
    case Direction::NONE:
        break;
    }
    this->shape.setPosition(position);
}

bool Creature::handleCreatureKeyPress(const sf::Event::KeyEvent& event)
{
    bool handled = true;
    switch (event.code)
    {
    case sf::Keyboard::Up:
        this->direction = Direction::UP;
        break;
    case sf::Keyboard::Down:
        this->direction = Direction::DOWN;
        break;
    case sf::Keyboard::Left:
        this->direction = Direction::LEFT;
        break;
    case sf::Keyboard::Right:
        this->direction = Direction::RIGHT;
        break;
    default:
        handled = false;
        break;
    }
    return handled;
}

bool Creature::handleCreatureKeyRelease(const sf::Event::KeyEvent& event)
{
    bool handled = true;
    switch (event.code)
    {
    case sf::Keyboard::Up:
        if (this->direction == Direction::UP)
        {
            this->direction = Direction::NONE;
        }
        break;
    case sf::Keyboard::Down:
        if (this->direction == Direction::DOWN)
        {
            this->direction = Direction::NONE;
        }
        break;
    case sf::Keyboard::Left:
        if (this->direction == Direction::LEFT)
        {
            this->direction = Direction::NONE;
        }
        break;
    case sf::Keyboard::Right:
        if (this->direction == Direction::RIGHT)
        {
            this->direction = Direction::NONE;
        }
        break;
    default:
        handled = false;
        break;
    }

    return handled;
}