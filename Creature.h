#include "Utilities.h"
#include <SFML/Graphics.hpp>
#pragma once
enum struct Direction {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
class Creature{
public:
	Creature();
	sf::CircleShape shape;
	Direction direction;
	void updateCreature(float elapsedTime);
	bool handleCreatureKeyPress(const sf::Event::KeyEvent& event);
	bool handleCreatureKeyRelease(const sf::Event::KeyEvent& event);
};

