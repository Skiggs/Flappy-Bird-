#pragma once

#include <SFML/Graphics.hpp>
#include"Game.hpp"
#include<vector>
#include"DEFINITIONS.hpp"

namespace Sonar {
	class Pipe
	{
	public:
		Pipe(GameDataRef data);

		void SpawnBottompipe();
		void SpawnTopPipe();
		void SpawnInvisiblePipe();
		void Movepipes(float dt);
		void DrawPipes();
		void RandomisePipeOffset();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataRef _data;
		
		std::vector<sf::Sprite> pipeSprites;

		int _landHeight;
		int _pipeSpawnOffset;
	};
}