#include <cstdio> 
#include <iostream>
#include "Bancada.hpp"

int main() {
  int q;
  char e;
  laboratorio::Bancada* bancadaLab = laboratorio::Bancada::getInstance();
  while(scanf("%d %c", &q, &e) != EOF) {
    if (e == 'p'){
      if(q>=0){
        printf("%d\n", bancadaLab->calculaMovimentosMinimos((unsigned int)q));
      }
    }else if(e =='r'){
      if(q>=0){
        bancadaLab->retiraRecipiente((unsigned int)q);
      }
    }else if(e =='i'){
      if(q>=0){
        bancadaLab->adicionaRecipiente((unsigned int)(q));
      }
    }
  }
  bancadaLab->destruirBancada();
  return 0;
}
