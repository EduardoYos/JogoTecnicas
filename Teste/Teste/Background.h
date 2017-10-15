#pragma once

#include "stdafx.h"

class Background
{
private:
	ALLEGRO_BITMAP* imagem;

public:
	Background(ALLEGRO_BITMAP* img) { imagem = img; } //recebe o caminho da imagem e salva ela 
	~Background() {}

	void atualiza() { al_draw_bitmap(imagem, 0, 0, 0); } //atualiza a imagem na posição (x, z) sem inverter
};