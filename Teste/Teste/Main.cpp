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

#include "Janela.h"
#include "Background.h"
#include "Personagem.h"
#include "Evento.h"


class Menu
{
private:
	ALLEGRO_FONT* fonte;

public:
	Menu() { fonte = NULL; setup(); }
	~Menu() { al_destroy_font(fonte); }

	void setup() 
	{
		al_init_font_addon();
		al_init_ttf_addon();
		al_init_image_addon();
		fonte = al_load_font("BRADHITC.ttf", 48, 0);
	}

	void mostrar() 
	{
		al_draw_text(fonte, al_map_rgb(255, 0, 0), 50, 20, ALLEGRO_ALIGN_LEFT, "1 - Continuar Jogo");
		al_draw_text(fonte, al_map_rgb(255, 0, 0), 100, 20, ALLEGRO_ALIGN_LEFT, "2 - Novo Jogo");
		al_draw_text(fonte, al_map_rgb(255, 0, 0), 150, 20, ALLEGRO_ALIGN_LEFT, "3 - Carregar Jogo");
		al_draw_text(fonte, al_map_rgb(255, 0, 0), 200, 20, ALLEGRO_ALIGN_LEFT, "4 - Salvar Jogo");
		al_draw_text(fonte, al_map_rgb(255, 0, 0), 250, 20, ALLEGRO_ALIGN_LEFT, "5 - Ranking Jogo");
		al_draw_text(fonte, al_map_rgb(255, 0, 0), 300, 20, ALLEGRO_ALIGN_LEFT, "0 - Sair");

		al_rest(5);
	}
	void sair() {  }
};


class Jogo
{
private:
	Janela* janela;
	Background* background;
	Personagem* personagem;
	Evento* evento;
	Menu* menu;

public:
	Jogo()
	{
		setup(); //Configura o jogo
		executar(); //Executa o Jogo
	}
	~Jogo() { }

	void setup() 
	{
		al_init(); //inicializa o allegro
		al_init_image_addon(); //inicializa o addon para imagens

		janela = new Janela(1024, 768); //cria janela
		background = new Background(al_load_bitmap("Imagens\\Background\\FinalBattleForest.png")); //Cria o Background
		personagem = new Personagem(10, 10, al_load_bitmap("Imagens\\Personagem\\Idle\\Idle__000.png")); //Cria o Personagem
		evento = new Evento();
		evento->setJanela(janela); //Seta a janela para que possa estabelecer de qual janela irá receber eventos
		evento->setup();
		//menu = new Menu(); ///FONTE NÃO CARREGANDO
	}

	void executar()
	{
		bool fim = false;

		//menu->mostrar();

		while (!fim) //LOOP principal
		{
			evento->esperaEvento();

			background->atualiza(); //Atualiza o Background
			personagem->movimento(evento->getTecla()); //Ação do Personagem
			personagem->atualiza(); //atualiza o personagem na tela

			al_flip_display(); //Atualiza a tela

			if (evento->eventoTipo() == ALLEGRO_EVENT_DISPLAY_CLOSE) //Se o X da janela foi clicado, então fecha o jgo
				fim = true;
			if (evento->getTecla() == ALLEGRO_KEY_ESCAPE) //se o evento foi o "ESCAPE" (ESC) do teclado
				fim = true;

		}

		delete janela;
		delete background;
		delete personagem;
		delete evento;
		//delete menu;
	}
};



int main(void)
{
	Jogo j;
	return 0;
}

