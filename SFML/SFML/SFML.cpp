// SFML.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"

#include "Background.h"
#include "Personagem.h"

class Jogo
{
private:
	sf::RenderWindow* janela;
	sf::Event evento;
	sf::Keyboard keyboard;
	Background* background;
	Personagem* personagem;

public:
	virtual ~Jogo() {}
	Jogo() 
	{
		iniciar();
		executar();
	}

	void iniciar()
	{
		janela = new sf::RenderWindow(sf::VideoMode(1024, 768), "Meu Jogo");
		background = new Background("Imagens\\Background\\FinalBattleForest.png");
		personagem = new Personagem("Imagens\\Personagem\\Idle\\Idle__000.png");
	}

	void executar()
	{
		while (janela->isOpen())
		{
			while (janela->pollEvent(evento))
			{
				if (evento.type == sf::Event::Closed)
					janela->close();
			}
			if (keyboard.isKeyPressed(keyboard.A))
				personagem->movimentarA();
			if (keyboard.isKeyPressed(keyboard.D))
				personagem->movimentarD();
			if (keyboard.isKeyPressed(keyboard.W))
				personagem->movimentarW();
			if (keyboard.isKeyPressed(keyboard.S))
				personagem->movimentarS();
			
			
			janela->clear();	///LIMPA A TELA
			janela->draw(background->getSprite()); //desenha o fundo
			janela->draw(personagem->getSprite()); //desenha o personagem
			janela->display();	///ATUALIZA A TELA
		}
	}
};

int main()
{
	Jogo j;

	return 0;
}