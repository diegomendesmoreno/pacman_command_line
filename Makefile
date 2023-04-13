CC=clang

all:
	$(CC) -o main main.c pacman/pacman.c pacman/map.c pacman/personagem.c
	./main

test:
	mv pacman/test/test_map pacman/test/test_map.c
	$(CC) -o main pacman/test/test_map.c pacman/map.c
	mv pacman/test/test_map.c pacman/test/test_map
	./main

clean:
	rm -rf *.o main
