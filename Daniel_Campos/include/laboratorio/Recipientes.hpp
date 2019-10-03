#ifndef RECIPIENTES_H
#define RECIPIENTES_H
#include "./include/laboratorio/Celula.hpp"
namespace laboratorio{
	class Recipientes{
	public:
		static Recipientes* getInstance();
		static void destruirRecipientes();

		void limpa();
		void insere(unsigned int medida);
		void retira(unsigned int medida);
		Celula* getPrimeiro();
		bool isVazia();
	private:
		static Recipientes* singleton;
		Celula* primeiro,ultimo;
		Recipientes();
		void retiraPrimeiro();
		~Recipientes();
	};
}

#endif