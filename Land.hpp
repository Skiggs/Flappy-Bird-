#pragma once

#include<SFML/Graphics.hpp>
#include "Game.hpp"
#include<vector>

namespace Sonar {
	
	class Land
	{
	public:
		Land(GameDataRef data);

		void MoveLand(float dt);
		void DrawLand();

		const std::vector<sf::Sprite> &GetSprite() const;

	private:
		GameDataRef _data;

		std::vector < sf::Sprite > _landSprite;
	};
}