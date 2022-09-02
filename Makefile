all:
	$(CC) -o main main.c pacman/pacman.c pacman/mapa.c pacman/personagem.c
	./main

test:
	$(CC) -o main pacman/test/test_map.c pacman/mapa.c
	./main

clean:
	rm -rf *.o main
