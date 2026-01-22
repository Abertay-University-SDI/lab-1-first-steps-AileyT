#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	sf::CircleShape m_Player;
	sf::CircleShape m_food;
	// Default variables for level class.
	static enum direction{ UP, DOWN, LEFT, RIGHT };
	direction lastDirection;
	

	
};