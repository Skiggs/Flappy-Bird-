#include "Pipe.hpp"

#include<iostream> 

namespace Sonar {

Pipe::Pipe(GameDataRef data) : _data(data)
{
	_landHeight = _data->assets.GetTexture("Land").getSize().y;
	_pipeSpawnOffset = 0;
}
void Pipe::SpawnBottompipe() {
	sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y -
		sprite.getGlobalBounds().height - _pipeSpawnOffset);

	pipeSprites.push_back(sprite);
}

void Pipe::SpawnTopPipe() {
	sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));

	sprite.setPosition(_data->window.getSize().x, -_pipeSpawnOffset);

	pipeSprites.push_back(sprite);
}

void Pipe::SpawnInvisiblePipe() {

	sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));

	sprite.setPosition(_data->window.getSize().x, -_pipeSpawnOffset);

	sprite.setColor(sf::Color(0, 0, 0, 0));

	pipeSprites.push_back(sprite);



}

void Pipe::Movepipes(float dt)
{
	for (unsigned short int i = 0; i < pipeSprites.size(); i++)
	{
		if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width)
		{
			pipeSprites.erase(pipeSprites.begin() + i);
		}

		else
		{

			float movement = PIPE_MOVEMENT_SPEED * dt;

			pipeSprites.at(i).move(-movement, 0);
		}
		}

	
}

void Pipe::DrawPipes()
{
	for (unsigned short int i = 0; i < pipeSprites.size(); i++)
	{
		_data->window.draw(pipeSprites.at(i));
	}
}

void Pipe::RandomisePipeOffset()
{
	_pipeSpawnOffset = rand() % (_landHeight + 1);
}

const std::vector<sf::Sprite> &Pipe::GetSprites() const
{
	return pipeSprites;
}
}