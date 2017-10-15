#pragma once

#include "stdafx.h"

class Janela
{
private:
	ALLEGRO_DISPLAY* j;
	int a; //Altura
	int l; //Largura

public:
	Janela(int la, int al) { setLargura(la); setAltura(al); setDisplay(); } //cria a janela 
	~Janela() { al_destroy_display(j); } //Finaliza a Janela

	void setAltura(int al) { a = al; }
	void setLargura(int la) { l = la; }
	void setDisplay() { j = al_create_display(l, a); }

	int getAltura() { return a; }
	int getLargura() { return l; }
	ALLEGRO_DISPLAY* getDisplay() { return j; }
};