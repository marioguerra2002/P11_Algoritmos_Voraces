CC=g++
CFLAGS=-O0 -g -Wall
DEPS = CambioDeMonedas.h
OBJ = main.o

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o P11_Algoritmos_Voraces


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: algoritmosvoraces

language: main.o
	g++ -o algoritmosvoraces main.cc CambioDeMonedas.cc

clean:
	rm -f *.o