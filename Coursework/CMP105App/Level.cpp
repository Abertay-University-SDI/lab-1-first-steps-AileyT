#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_Player = sf::CircleShape(10.f);
	m_Player.setFillColor(sf::Color::Green);
	m_Player.setPosition({300,300});
	m_food = sf::CircleShape(5.f);
	m_food.setFillColor(sf::Color::Magenta);
	m_food.setPosition({float(rand() % 800),float(rand()% 600)});
	

}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}
	if(m_input.isKeyDown(sf::Keyboard::Scancode::W))
	{
		lastDirection = UP;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S))
	{
		lastDirection = DOWN;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A))
	{
		lastDirection = LEFT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D))
	{
		lastDirection = RIGHT;
	}


}

// Update game objects
void Level::update(float dt)
{
	switch (lastDirection)
	{
	case direction::UP:
		m_Player.move({ 0.f, -100.f * dt });
		break;
	case direction::DOWN:
		m_Player.move({ 0.f, 100.f * dt });
		break;
	case direction::LEFT:
		m_Player.move({ -100 * dt ,0 });
		break;
	case direction::RIGHT:
		m_Player.move({ 100 * dt ,0 });
		break;
	}
	auto pos = m_Player.getPosition();

	/// WK TODO:
	/*
	
	1. Parameterise this 

	2. Consider the fact that the origin in the top-left of the bounding box (using radius)

	3. 
	
	*/
	if (pos.x < 0 || pos.x > m_window.getSize().x || pos.y < 0 || pos.y > 600)
	{
		 m_Player.setPosition({ 300,300 });
	}
	auto fpos = m_food.getPosition();
	float hypotanus = sqrt((fpos.x - pos.x) * (fpos.x - pos.x) + (fpos.y - pos.y ) * (fpos.y - pos.y ));
	std::cout << hypotanus << std::endl;
	if(hypotanus < 6 && hypotanus > -6)
	{
		
		m_food.setPosition({float(rand() % 800),float(rand() % 600)});
	}

	
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_Player);
	m_window.draw(m_food); 
	endDraw();
}

