#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "./include/laboratorio/Fila.hpp"
#include "./include/laboratorio/Recipientes.hpp"
#include "./include/laboratorio/Celula.hpp"

namespace laboratorio{
	class Calculadora{
	public:
		static Calculadora* getInstance();
		static void destruirCalculadora();
		unsigned int calcularMinimo(unsigned int valorMedido);

	private:
		static Calculadora* singleton;
		Calculadora();
		~Calculadora();
	};
}



#endif