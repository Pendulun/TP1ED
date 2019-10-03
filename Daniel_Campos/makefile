# == VARIAVEIS ===
# ================
#
# Podemos declarar algumas variaveis dentro do Makefile (sintaxe similar a bash)
# Isso facilita o seu trabalho caso voce opte trocar alguma versao do
# compilador ou flag para seu processo de compilacao
# Uma variavel com nome VAR eh declarada da seguinte maneira:
# 	VAR=conteudo
# e eh chamada atraves do comando $(VAR)

CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1 # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult
BUILD=./build/
SRC=./src/
INCLUDE=./include/
MODULO=laboratorio/


$(EXEC): $(BUILD)main.o $(BUILD)$(MODULO)Bancada.o $(BUILD)$(MODULO)Celula.o $(BUILD)$(MODULO)Calculadora.o $(BUILD)$(MODULO)Recipientes.o $(BUILD)$(MODULO)Fila.o
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILD)main.o $(BUILD)$(MODULO)*.o

$(BUILD)main.o: $(SRC)main.cpp $(INCLUDE)$(MODULO)Bancada.hpp  
	$(CC) $(CFLAGS) -I $(INCLUDE)$(MODULO) -c $(SRC)main.cpp  

$(BUILD)$(MODULO)Bancada.o: $(SRC)$(MODULO)Bancada.cpp $(INCLUDE)$(MODULO)Bancada.hpp $(INCLUDE)$(MODULO)Calculadora.hpp $(INCLUDE)$(MODULO)Recipientes.hpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(MODULO) -c $(SRC)$(MODULO)Bancada.cpp

$(BUILD)$(MODULO)Celula.o: $(SRC)$(MODULO)Celula.cpp $(INCLUDE)$(MODULO)Celula.hpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(MODULO) -c $(SRC)$(MODULO)Celula.cpp 

$(BUILD)$(MODULO)Calculadora.o: $(SRC)$(MODULO)Calculadora.cpp $(INCLUDE)$(MODULO)Calculadora.hpp $(INCLUDE)$(MODULO)Fila.hpp $(INCLUDE)$(MODULO)Recipientes.hpp $(INCLUDE)$(MODULO)Celula.hpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(MODULO) -c $(SRC)$(MODULO)Calculadora.cpp 

$(BUILD)$(MODULO)Recipientes.o: $(SRC)$(MODULO)Recipientes.cpp $(INCLUDE)$(MODULO)Recipientes.hpp $(INCLUDE)$(MODULO)Celula.hpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(MODULO) -c $(SRC)$(MODULO)Recipientes.cpp 

$(BUILD)$(MODULO)Fila.o: $(SRC)$(MODULO)Fila.cpp $(INCLUDE)$(MODULO)Fila.hpp $(INCLUDE)$(MODULO)Celula.hpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(MODULO) -c $(SRC)$(MODULO)Fila.cpp 

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf foo.o
