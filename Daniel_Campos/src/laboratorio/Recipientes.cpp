#include "Recipientes.hpp"
#include <cstdio>
namespace laboratorio{
	
	Recipientes* Recipientes::singleton = nullptr;

	Recipientes::Recipientes(){
		this->primeiro=new Celula(0);//Célula cabeça
		this->ultimo=this->primeiro;
	}

	Recipientes* Recipientes::getInstance(){
		if (Recipientes::singleton == nullptr){
			Recipientes::singleton = new Recipientes();
		}
		
		return Recipientes::singleton;
	}

	void Recipientes::destruirRecipientes(){
		delete Recipientes::singleton;
	}

	bool Recipientes::isVazia(){
		return ((this->primeiro==this->ultimo));
	}

	void Recipientes::limpa(){
		while(!isVazia()){
			retiraPrimeiro();
		}
	}

	//Usado para limpar a lista de recipientes
	void Recipientes::retiraPrimeiro(){
		Celula* itemRetirado=this->primeiro;
		this->primeiro=this->primeiro->getProx();
		delete itemRetirado;
	}

	void Recipientes::insere(unsigned int medida){
		this->ultimo->setProx(new Celula(medida));
		this->ultimo=this->ultimo->getProx();
	}

	Celula* Recipientes::getPrimeiro(){
		return this->primeiro->getProx();
	}

	void Recipientes::retira(unsigned int medida){
		if(!isVazia()){
			//Anda de dois em dois
			Celula* celulaRetirada=this->primeiro->getProx();
			Celula* anterior=nullptr;
			bool retirou=false;
			//Enquanto não retirar
			do{
				if(celulaRetirada->getMedida()==medida){
					//se for a primeira célula não cabeça, atualiza essa célula
					if(anterior==nullptr){
						this->primeiro->setProx(celulaRetirada->getProx());
					//se for diferente da primeira, reaponta o prox do anterior
					}else{
						//Se a célula a ser retirada for a última, att "ultimo"
						if(celulaRetirada==this->ultimo){
							this->ultimo=anterior;
						}
						anterior->setProx(celulaRetirada->getProx());
					}
					//deleta da memória
					delete celulaRetirada;
					retirou=true;
				}else{
					//Atualiza as células analisadas
					anterior=celulaRetirada;
					celulaRetirada=celulaRetirada->getProx();
				}
				//se chegar no final da lista
				if(!retirou){
					if(celulaRetirada==nullptr){
						retirou=true;
					}
				}	
			}while(!retirou);
		}
	}

	Recipientes::~Recipientes(){
		limpa();
		delete this->primeiro;
	}
}