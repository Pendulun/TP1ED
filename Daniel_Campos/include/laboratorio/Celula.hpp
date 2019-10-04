#ifndef CELULA_H
#define CELULA_H

namespace laboratorio{
	class Celula{
	public:
		void setMedida(unsigned int novaMedida);
		unsigned int getMedida();
		void setProx(laboratorio::Celula* proxCelula);
		laboratorio::Celula* getProx();
		Celula(unsigned int novaMedida);
	private:
		unsigned int medida;
		laboratorio::Celula* prox;
	};

}
#endif