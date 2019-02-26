

#include<sstream>
#include"GameState.hpp"
#include"DEFINITIONS.hpp"
#include"MainMenuState.hpp"

#include<iostream>

namespace Sonar {
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);

		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

		_data->assets.LoadTexture("Land", LAND_FILEPATH);

		_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);

		_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);

		_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);

		_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

		pipe = new Pipe(_data);
		
		land = new Land(_data);

		bird = new Bird(_data);

		flash = new Flash(_data);
		
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		_gameState = GameStates::eReady;

	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					bird->Tap();
				}
			}

		}
	}

	void GameState::Update(float dt)
	{

		if (GameStates::eGameOver != _gameState)
		{
		
			bird->Animate(dt);
			land->MoveLand(dt);
		}

		if (GameStates::ePlaying == _gameState)
		{

			pipe->Movepipes(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{
				pipe->RandomisePipeOffset();
				pipe->SpawnBottompipe();
				pipe->SpawnInvisiblePipe();
				pipe->SpawnTopPipe();

				clock.restart();
			}

			bird->Update(dt);
			std::vector<sf::Sprite> landSprites = land->GetSprite();

			for( int i = 0; i < landSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(), landSprites.at(i)))
				{
					_gameState = GameStates::eGameOver;
				}
			}

			std::vector<sf::Sprite> PipeSprites = pipe->GetSprites();

			for (int i = 0; i < PipeSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(), PipeSprites.at(i)))
				{
					_gameState = GameStates::eGameOver;
				}
			}
			
		}

		if (GameStates::eGameOver == _gameState)
		{
			flash->Show(dt);
		}
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		 pipe->DrawPipes();
		 land->DrawLand();
		 bird->Draw();
		 flash->Draw();
		_data->window.display();
	}
}