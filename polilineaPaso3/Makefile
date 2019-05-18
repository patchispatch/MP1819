# Objetivo global que genera el programa principal
all:  polilinea 

# objetivo para generar el ejecutable final. Depende de los
# archivos objeto generados a partir de prueba.cpp y polilinea.cpp.
# La linea de abajo indica el comando necesario para hacer la
# generacion. Se observa el uso de -g para poder ejecutar con
# valgring y ver los problemas de memoria
polilinea:	prueba.o polilinea.o
	g++ -g -o bin/polilinea obj/prueba.o obj/polilinea.o 

# directiva para compilar prueba.cpp. Se indica tambien los archivos
# de cabecera que necesita. De esta forma, si hubiera un cambio en
# alguno de ellos se dispara esta regla
prueba.o:	src/prueba.cpp include/polilinea.h include/punto.h
	g++ -g -c -o obj/prueba.o src/prueba.cpp -I./include

polilinea.o:	src/polilinea.cpp include/polilinea.h include/punto.h
	g++ -g -c -o obj/polilinea.o -I./include src/polilinea.cpp

# objetivo para limpiar los archivos objeto y el ejecutable
clean:
	rm obj/*.o bin/*


