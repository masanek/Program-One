shell: main.c process.c input.c
	gcc -ggdb -Wall -pedantic -o shell main.c process.c input.c
