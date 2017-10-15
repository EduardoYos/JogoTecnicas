#pragma once

#include "stdafx.h"

class Personagem
{
private:
	int posx, posy; //Posição do personagem

	ALLEGRO_BITMAP* imagem; //Imagem do personagem

public:
	Personagem(int x = 0, int y = 0, ALLEGRO_BITMAP* img = NULL) //salva a posição e o sprite do personagem
	{
		posx = x; posy = y; imagem = img;
	}
	~Personagem() {}

	void movimento(int tecla) 
	{
		if (tecla == ALLEGRO_KEY_W, ALLEGRO_KEY_S, ALLEGRO_KEY_D, ALLEGRO_KEY_A)
			atualizaPos(tecla);
	}

	void atualiza() { al_draw_bitmap(imagem, posx, posy, 0); } //Desenha o personagem na tela
	void atualizaPos(int tecla) //atualiza a posição
	{
		if (tecla == ALLEGRO_KEY_W)
			posy -= 2;
		if (tecla == ALLEGRO_KEY_S) //O eixo y é prositivo para baixo (matriz)
			posy += 2;
		if (tecla == ALLEGRO_KEY_D) //O eixo x é positivo para a direita (matriz)
			posx += 2;
		if (tecla == ALLEGRO_KEY_A)
			posx -= 2;

		atualiza();
	}
};