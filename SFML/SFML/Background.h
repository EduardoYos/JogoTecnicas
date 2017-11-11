#pragma once

#include "stdafx.h"

class Background
{
private:
	sf::Texture texture;
	sf::Sprite imagem;

public:
	Background(string const s)	//recebe o caminho da imagem
	{
		texture.loadFromFile(s);	//carrega a imagem como textura
		imagem.setTexture(texture);	//salva a textura como imagem (background)
	}
	~Background() {	}

	sf::Texture getTextura() { return texture; }
	sf::Sprite getSprite() { return imagem; }
};

/*
	Implementar:
	- Cena
	- Ch�o (colis�o)
	- Parede de in�cio e fim (pro jogador n�o ir pro limbo)
	- In�cio e fim do mapa (aqui ou na progress�o???)
*/