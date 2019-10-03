#include "include/laboratorio/Recipientes.hpp"
namespace laboratorio{
	
	Recipientes::singleton = nullptr;

	Recipientes::Recipientes(){
		this->primeiro=nullptr;
		this->ultimo=nullptr;
	}

	static Recipiente::Recipientes* Recipientes::get_instance(){
		if (Recipientes::singleton == nullptr){
			Recipientes::singleton = new Recipientes();
		}
		
		return Recipientes::singleton;
	}

	static void Recipientes::destruirRecipientes(){
		delete Recipientes::singleton;
	}

	bool Recipientes::isVazia(){
		return this->primeiro==nullptr&&this->ultimo==nullptr;
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
		this->ultimo->setProx() = new Celula(medida);
		this->ultimo=this->ultimo->getProx();
	}

	Celula* Recipientes::getPrimeiro(){
		return this->primeiro;
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
						this->primeiro->setProx()=this->primeiro->getProx()->getProx();
					//se for diferente da primeira, reaponta o prox do anterior
					}else{
						anterior->setProx()=celulaRetirada->getProx();
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
				if(celulaRetirada==nullptr){
					retirou=true;
				}
			}while(!retirou);
		}
	}

	void Recipientes::~Recipientes(){
		limpa();
	}
}