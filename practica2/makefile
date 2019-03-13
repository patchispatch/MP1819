# Definición de macros para definir las carpetas de trabajo

BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
DOC=./doc

# Opciones de compilación
# -Wall muestra todas las advertencias
# -g compila en modo "depuración"

OPT= -std=c++11 -Wall -g

# Nombre de la práctica
PRJ=practica2

# Reglas:

all : $(BIN)/intervalo

$(BIN)/intervalo : $(OBJ)/intervalo.o $(OBJ)/main.o
	g++ -o $(BIN)/intervalo $(OBJ)/intervalo.o $(OBJ)/main.o

$(OBJ)/intervalo.o : $(SRC)/intervalo.cpp $(INC)/intervalo.h
	g++ $(OPT) -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INC)

$(OBJ)/main.o : $(SRC)/main.cpp $(INC)/intervalo.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)


clean:
	@echo "Limpiando ... "
	rm -rf $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/* $(DOC)/latex $(DOC)/html

zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *

doxy:
	doxygen doc/intervalo.doxy
