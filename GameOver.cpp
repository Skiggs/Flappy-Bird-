

#include<sstream>
#include"GameOver.hpp"
#include"DEFINITIONS.hpp"
#include"MainMenuState.hpp"
#include<iostream>

namespace Sonar {
	GameOver::GameOver(GameDataRef data) : _data(data)
	{

	}

	void GameOver::Init()
	{
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));

	}

	void GameOver::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void GameOver::Update(float dt)
	{

	}

	void GameOver::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);

		_data->window.display();
	}
}