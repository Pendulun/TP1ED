#include "Calculadora.hpp"
#include <cstdio>

namespace laboratorio{

	Calculadora* Calculadora::singleton=nullptr;

	Calculadora::Calculadora(){}

	Calculadora* Calculadora::getInstance(){
		if (Calculadora::singleton == nullptr){
			Calculadora::singleton = new Calculadora();
		}
		return Calculadora::singleton;
	}

	void Calculadora::destruirCalculadora(){
		delete Calculadora::singleton;
	}

	Calculadora::~Calculadora(){}

	//Calcula o mínimo de movimentos para se chegar ao valor necessário "valorMedido"
	//de acordo com os recipientes
	unsigned int Calculadora::calcularMinimo(unsigned int valorMedido){
		//Se existem Recipientes
		if(!Recipientes::getInstance()->isVazia()){
			if(valorMedido==0){
				return 0;
			}
			unsigned int movimentos=0;
			//Cria uma fila de combinações e enfileira "0"
			Fila* combinacoes=new Fila();
			combinacoes->enfileira(0);
			//Enquanto houver combinação a ser analisada
			while(!combinacoes->vazia()){
				Celula* recipiente=Recipientes::getInstance()->getPrimeiro();
				//Usa todos os recipientes para gerar combinações da combinação atual
				while(recipiente!=nullptr){
					unsigned int medida = combinacoes->getPrimeiro()->getMedida()+recipiente->getMedida();
					if(medida==valorMedido){
						delete combinacoes;
						return movimentos+1;
					}else{
						combinacoes->enfileira(medida);
					}
					if(recipiente->getMedida()<combinacoes->getPrimeiro()->getMedida()){
						medida=combinacoes->getPrimeiro()->getMedida()-recipiente->getMedida();
						if(medida==valorMedido){
							delete combinacoes;
							return movimentos+1;
						}else{
							combinacoes->enfileira(medida);
						}
					}
					recipiente=recipiente->getProx();
				}
				//Se a combinação analisada for a última possível com os movimentos atuais
				if(combinacoes->isPrimeiroItemFim()){
					movimentos++;
				}
				//Retira a combinação analisada da fila
				combinacoes->desenfileira();
			}
		}else{
			return 0;
		}
	}
}