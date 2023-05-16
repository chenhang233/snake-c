ALL: snake.out


snake.out:main.c map.c snake.c map.h snake.h main.h
	gcc -lpthread main.c map.c snake.c -o snake.out

clean:
	-rm -rf  snake.out