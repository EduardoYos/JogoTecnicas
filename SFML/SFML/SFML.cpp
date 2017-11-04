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
	sf::View* camera;

public:
	virtual ~Jogo() {}
	Jogo() 
	{
		iniciar();
		executar();
	}

	void iniciar()
	{
		janela = new sf::RenderWindow(sf::VideoMode(1024, 768), "Meu Jogo");	//CRIA UMA JANELA
		janela->setPosition(sf::Vector2i(0, 0));	//SETA A POSIÇÃO DA JANELA NA TELA DO USUARIO

		background = new Background("Imagens\\Cidade.png");	//CRIA O BACKGROUND
		personagem = new Personagem("Imagens\\Player1.png"); //CRIA O PERSONAGEM

		camera = new sf::View(sf::Vector2f(personagem->getPosX()+20, 207/2), sf::Vector2f(276, 207));
		personagem->setCamera(camera);

		janela->setView(*camera);
	}

	void movimentarPersonagem()
	{
		personagem->gravidade();
		if (keyboard.isKeyPressed(keyboard.A))
			personagem->acao("A");
		if (keyboard.isKeyPressed(keyboard.D))
			personagem->acao("D");
		if (keyboard.isKeyPressed(keyboard.W))
			personagem->acao("W");
		return;
	}

	void atualizarEcra()
	{
		janela->clear();	///LIMPA A TELA
		janela->draw(background->getSprite()); //desenha o fundo
		janela->draw(personagem->getSprite()); //desenha o personagem
		personagem->mudaEstado("parado");
		janela->setView(*camera);
		janela->display();	///ATUALIZA A TELA
		return;
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

			movimentarPersonagem();
			atualizarEcra();
		}
	}
};

int main()
{
	Jogo j;

	return 0;
}