#ifndef BANCADA_H
#define BANCADA_H
#include "include/laboratorio/Calculadora.hpp"
#include "include/laboratorio/Recipientes.hpp"
namespace laboratorio{
class Bancada{
public:
	static Bancada* getInstance();
	static void destruirBancada();
	
	void adicionaRecipiente(unsigned int medidaNova);
	void retiraRecipiente(unsigned int medidaRetirada);
	unsigned int calculaMovimentosMinimos(unsigned int medidaCalculada);

private:
	static Bancada* singleton;
	Bancada();
	~Bancada();
	Calculadora* calculadora=nullptr;
	Recipientes* listaRecipientes=nullptr;
};



}


#endif