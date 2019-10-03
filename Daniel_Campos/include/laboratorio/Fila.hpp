#ifndef FILA_H
#define FILA_H
#include "./include/laboratorio/Celula.hpp"

namespace laboratorio{
	class Fila{
	public:
		Fila();
		bool vazia();
		void enfileira(unsigned int novaMedida);
		void desenfileira();
		bool isPrimeiroItemFim();
		Celula* getPrimeiro();
		~Fila();
	private:
		void limpa();
		Celula* frente,tras,fimNivel;
	};
}

#endif