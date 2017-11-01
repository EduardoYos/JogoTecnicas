#pragma once

#include "stdafx.h"

class Personagem
{
private:
	sf::Vector2<float> pos;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	~Personagem() {}
	Personagem(string const s)
	{
		texture.loadFromFile(s);
		sprite.setTexture(texture);

		pos.x = 400;
		pos.y = 400;
	}

	void movimentarA() 
	{
		pos.x -= .5;
		sprite.setPosition(pos);
	}
	void movimentarD() 
	{
		pos.x += .5;
		sprite.setPosition(pos);
	}
	void movimentarW()
	{
		pos.y -= .5;
		sprite.setPosition(pos);
	}
	void movimentarS()
	{
		pos.y += .5;
		sprite.setPosition(pos);
	}

	sf::Sprite getSprite() { return sprite; }
	 
};