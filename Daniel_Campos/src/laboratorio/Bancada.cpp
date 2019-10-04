#include "Bancada.hpp"
namespace laboratorio{

	Bancada* Bancada::singleton=nullptr;

	Bancada::Bancada(){
		this->calculadora=Calculadora::getInstance();
		this->listaRecipientes=Recipientes::getInstance();
	}

	Bancada* Bancada::getInstance(){
		if (Bancada::singleton == nullptr){
			Bancada::singleton = new Bancada();
		}
		return Bancada::singleton;
	}

	void Bancada::destruirBancada(){
		delete Bancada::singleton;
	}

	Bancada::~Bancada(){
		this->calculadora->destruirCalculadora();
		this->listaRecipientes->destruirRecipientes();
	}

	void Bancada::adicionaRecipiente(unsigned int medidaNova){
		this->listaRecipientes->insere(medidaNova);
	}

	void Bancada::retiraRecipiente(unsigned int medidaRetirada){
		this->listaRecipientes->retira(medidaRetirada);
	}

	unsigned int Bancada::calculaMovimentosMinimos(unsigned int medidaCalculada){
		return this->calculadora->calcularMinimo(medidaCalculada);
	}


}