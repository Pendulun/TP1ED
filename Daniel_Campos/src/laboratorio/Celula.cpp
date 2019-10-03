#include "include/laboratorio/Celula.hpp"

namespace laboratorio{

	void Celula::setMedida(unsigned int novaMedida){
		this->medida=novaMedida;
	}

	unsigned int Celula::getMedida(){
		return this->medida;
	}

	void Celula::setProx(laboratorio::Celula &proxCelula){
		this->prox=proxCelula;
	}

	laboratorio::Celula* Celula::getProx(){
		return this->prox;
	}

	Celula::Celula(unsigned int novaMedida){
		this->medida=novaMedida;
		this->prox=nullptr;
	}

}