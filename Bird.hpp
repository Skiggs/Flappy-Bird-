#pragma once

#include<SFML/Graphics.hpp>

#include"DEFINITIONS.hpp"
#include"Game.hpp"
#include<vector>

namespace Sonar {
	class Bird {
	public:
		Bird(GameDataRef data);

		void Draw();

		void Animate(float dt);

		void Update(float dt);

		void Tap();

		const sf::Sprite &GetSprite() const;

	private:
		GameDataRef _data;
		sf::Sprite birdSprite;
		std::vector<sf::Texture> _animationFrames;

		sf::Clock _clock;

		unsigned int _animationIterator;

		sf::Clock _movementClock;

		int birdState;

		float _rotation;

	};
}