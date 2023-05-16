ALL: snake.out


snake.out:main.c map.c snake.c food.c map.h snake.h main.h food.h
	gcc -lpthread main.c map.c snake.c food.c -o snake.out

clean:
	-rm -rf  snake.out