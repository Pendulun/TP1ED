#include "include/laboratorio/Fila.hpp"
#include "include/laboratorio/Celula.hpp"

namespace laboratorio{

	Fila::Fila(){
		this->frente=new Celula(NULL);//Cria o cabeça
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
		return this->frente->setProx()==this->fimNivel;
	}

	void Fila::enfileira(unsigned int novaMedida){
		Celula* novaCelula=new Celula(novaMedida);
		this->tras->setProx()=novaCelula;
		this->tras=this->tras->getProx();
		//Se for a primeira vez adicionando
		if(this->fimNivel==this->frente){
			this->fimNivel=this->tras;
		}
	}

	void Fila::desenfileira(){
		if(!vazia()){
			Celula* itemDesenfileirado=this->frente->getProx();
			this->frente->setProx()=itemDesenfileirado->getProx();
			if(itemDesenfileirado==this->fimNivel){
				this->fimNivel=this->tras;
			}
			delete itemDesenfileirado;
		}
	}

	Celula* Fila::getPrimeiro(){
		return this->frente->getProx();
	}

	Fila::~Fila(){
		limpa();
		delete this->frente;//Deleta o cabeça
	}
}