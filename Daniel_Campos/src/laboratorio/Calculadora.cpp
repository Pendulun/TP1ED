#include "include/laboratorio/Calculadora.hpp"
#include "include/laboratorio/Fila.hpp"
#include "include/laboratorio/Recipientes.hpp"
#include "include/laboratorio/Celula.hpp"
#include <exception>

namespace laboratorio{

	Calculadora::singleton=nullptr;

	Calculadora::Calculadora(){}

	static Calculadora* Calculadora::getInstance(){
		if (Calculadora::singleton == nullptr){
			Calculadora::singleton = new Calculadora();
		}
		return Calculadora::singleton;
	}

	static void Calculadora::destruirCalculadora(){
		delete Calculadora::singleton;
	}

	Calculadora::~Calculadora(){}

	//Calcula o mínimo de movimentos para se chegar ao valor necessário "valorMedido"
	//de acordo com os recipientes
	unsigned int Calculadora::calculaMinimo(unsigned int valorMedido){
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
				//Celula* possibilidade=combinacoes->getPrimeiro();
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
					try{
						medida=combinacoes->getPrimeiro()->getMedida()-recipiente->getMedida();
						if(medida==valorMedido){
							delete combinacoes;
							return movimentos+1;
						}else{
							combinacoes->enfileira(medida);
						}
					}catch(std::exception &e){
						//Para o caso de "medida" ser negativo
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