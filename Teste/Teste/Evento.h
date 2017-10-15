#pragma once

#include "stdafx.h"
#include "Janela.h"

class Evento
{
private:
	ALLEGRO_EVENT_QUEUE* fila_eventos;
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT t;
	Janela* j;

public:
	Evento() { }
	~Evento() { al_destroy_event_queue(fila_eventos); }

	void setup()
	{
		al_install_keyboard(); //inicializa o teclado
		fila_eventos = al_create_event_queue(); //criação da fila de eventos
		al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //a fila poderá registrar os eventos do teclado
		al_register_event_source(fila_eventos, al_get_display_event_source(j->getDisplay())); //A fila poderá registrar os eventos da Janela
		al_init_timeout(&t, 0.01); //tempo de espera para pegar um evento
	}
	void setJanela(Janela* ja) { j = ja; }
	void esperaEvento() { al_wait_for_event_until(fila_eventos, &ev, &t); } //Espera por 0.05s por algum evento
	ALLEGRO_EVENT_TYPE eventoTipo() { return ev.type; }
	int getTecla() { return ev.keyboard.keycode; }
};