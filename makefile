prog:main.o
	gcc main.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
main.o:main.c
	gcc -c main.c
