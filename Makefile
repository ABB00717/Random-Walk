all:
	gcc -o prog main.c `sdl2-config --cflags --libs` -g -Wall -Wextra
	./prog 50
