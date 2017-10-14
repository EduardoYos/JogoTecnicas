//Jogo Para a Disciplina de Tecnicas de Programação
//
//Referencia Online (Allegro): https://www.allegro.cc/manual/5/
//
//Requisitos Mínimos:
// - Menu
// - Single e Two Players
// - Min 2 Fases (Sequenciais ou Selecionadas)
// - 3 Tipos de Inimigos (incl. Boss)
// - Cada fase com min de 2 Tipos de Inimigos (c/ várias intancias de cada)
// - Ter Boss na ultima fase
// - 3 Tipos de Obstáculos
// - 1-10 Tipos de obstáculos por fase (c/ varias instancias de cada)
// - Ter representação grafica de instancias
// - Um cenário para cada fase c/ Obstáculos
// - Colisões entre inimigos e Jogador(es)
// - Leaderboards/Ranking
// - Pausar Jogo
// - Salvar Jogo
//
//
//

#include "stdafx.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <stdio.h>



class Janela
{
private:
	ALLEGRO_DISPLAY* janela;
	int h; //Altura
	int w; //Largura

public:
	Janela(int wi, int he) 
	{ h = he; w = wi; janela = al_create_display(w, h); }
	~Janela() { al_destroy_display(janela); } //Finaliza a Janela
};

class Background
{
private:
	ALLEGRO_BITMAP* imagem;

public:
	Background(ALLEGRO_BITMAP* img) { imagem = img;  }
	~Background() {}

	void atualiza() { al_draw_bitmap(imagem, 0, 0, 0); }
};

class Personagem
{
private:
	int posx, posy; //Posição do personagem
	ALLEGRO_BITMAP* imagem; //Imagem do personagem

public:
	Personagem(int x = 0, int y = 0, ALLEGRO_BITMAP* img = NULL) 
	{ posx = x; posy = y; imagem = img; }
	~Personagem() {}

	void atualiza() { al_draw_bitmap(imagem, posx, posy, 0); } //Desenha a imagem na tela
	void atualizaPos()
	{
		if (ALLEGRO_KEY_W)
			posy++;
		if (ALLEGRO_KEY_S)
			posy--;
		if (ALLEGRO_KEY_D)
			posx++;
		if (ALLEGRO_KEY_A)
			posx--;
	}
};

class Jogo
{
private:
	Janela* j;
	Background* b;
	Personagem* p;
	ALLEGRO_EVENT_QUEUE* fila_eventos;

public:
	Jogo()
	{
		al_init(); //inicializa o allegro
		al_init_image_addon(); //inicializa o addon para imagens
		al_install_keyboard();
		//fila_eventos = al_create_event_queue();
		//al_register_event_source(fila_eventos, al_get_keyboard_event_source());
		//al_register_event_source(fila_eventos, al_get_display_event_source(janela));

		j = new Janela(1024, 768);
		b = new Background(al_load_bitmap("Imagens\\Background\\FinalBattleForest.png"));
		p = new Personagem(10, 10, al_load_bitmap("Imagens\\Personagem\\Idle\\Idle__000.png"));

		executar();
	}
	~Jogo() { }

	void executar()
	{
		b->atualiza();

		while (1)
		{
			p->atualizaPos();
			
			p->atualiza();
			al_flip_display(); //Atualiza a tela
		}
	}
};

int main(void)
{
	Jogo j;

	al_rest(10);
	return 0;
}

