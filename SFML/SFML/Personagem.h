#pragma once

#include "stdafx.h"
#include "Entidade.h"
class Personagem
	: public Entidade
{
private:
	sf::Vector2f pos;
	sf::Texture parado;
	sf::Texture andando;
	sf::Sprite sprite;
	sf::View* camera;
	string estado;

public:
	Personagem();
	~Personagem() {}
	Personagem(string const s)
	{
		parado.loadFromFile(s, sf::IntRect(5, 2, 37, 38));		//CARREGAR OS SPRITES
		andando.loadFromFile(s, sf::IntRect(54, 44, 41, 41));
		sprite.setTexture(parado);

		pos.x = 120;
		pos.y = 120;
	}

	void acao(string tecla)
	{
		if (tecla == "A")
		{
			mudaEstado("andando");
			pos.x -= .01;
			camera->move(-.01, 0);
			sprite.setPosition(pos);
		}

		if (tecla == "D")
		{
			mudaEstado("andando");
			pos.x += .01;
			camera->move(.01, 0);
			sprite.setPosition(pos);
		}
		if (tecla == "W" && pos.y >= 119.8)
		{
			mudaEstado("parado");
			pos.y -= 50;
			sprite.setPosition(pos);
		}

		return;
	}

	void mudaEstado(string s)
	{
		if (s == "parado")
		{
			estado = "parado";
			sprite.setTexture(parado);
		}
		if (s == "andando")
		{
			estado = "andando";
			sprite.setTexture(andando);
		}
		return;
	}

	void gravidade()
	{
		if (pos.y < 120)
		{
			pos.y += 0.032;
		}
		return;
	}

	void setCamera(sf::View* c) { camera = c; }

	sf::Sprite getSprite() { return sprite; }

	float getPosX() { return pos.x; }
	 
};