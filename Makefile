CC = g++
CFLAGS = -I header
SRC = main.c src/arquivo.cpp src/grafo.cpp src/menu.c
OBJ = labirinto

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ)