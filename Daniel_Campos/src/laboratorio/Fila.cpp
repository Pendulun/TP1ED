#include "Fila.hpp"
#include <cstdio>

namespace laboratorio{

	Fila::Fila(){
		this->frente=new Celula(0);//Cria o cabeça com conteúdo irrelevante
		this->tras=this->frente;
		this->fimNivel=this->frente;
	}

	bool Fila::vazia(){
		return this->frente==this->tras;//Se ambos apontam para o cabeça
	}

	void Fila::limpa(){
		while(!vazia()){
			desenfileira();
		}
	}

	bool Fila::isPrimeiroItemFim(){
		return this->frente->getProx()==this->fimNivel;
	}

	void Fila::enfileira(unsigned int novaMedida){
		Celula* novaCelula=new Celula(novaMedida);
		this->tras->setProx(novaCelula);
		this->tras=this->tras->getProx();
		//Se for a primeira vez adicionando
		if(this->fimNivel==this->frente){
			this->fimNivel=this->tras;
		}
	}

	void Fila::desenfileira(){
		if(!vazia()){
			Celula* itemDesenfileirado=this->frente->getProx();
			this->frente->setProx(itemDesenfileirado->getProx());
			if(itemDesenfileirado==this->fimNivel){
				this->fimNivel=this->tras;
			}
			//Se o elemento a ser desenfileirado é o único elemento (tras)
			//tras apontará para frente
			if(itemDesenfileirado==this->tras){
				this->tras=this->frente;
			}
			delete itemDesenfileirado;

		}
	}

	Celula* Fila::getPrimeiro(){
		return this->frente->getProx();
	}


	Fila::~Fila(){
		limpa();
		//como frente e tras estão no mesmo lugar, um único delete serve para os dois
		delete this->frente;//Deleta o cabeça
	}
}