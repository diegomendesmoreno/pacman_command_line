all:
	$(CC) -o main main.c pacman/pacman.c pacman/map.c pacman/personagem.c
	./main

test:
	$(CC) -o main pacman/test/test_map.c pacman/map.c
	./main

clean:
	rm -rf *.o main
