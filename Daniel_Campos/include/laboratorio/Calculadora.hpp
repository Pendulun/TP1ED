#ifndef CALCULADORA_H
#define CALCULADORA_H

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