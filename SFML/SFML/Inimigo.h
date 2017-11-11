#pragma once
#include "Personagem.h"
class Inimigo
	: public Personagem
{
public:
	Inimigo();
	~Inimigo();
};

/*
	Implementar:
	 - virtual puro Ataques
	 - virtual puro Movimentação
	 - virtual puro IA
*/