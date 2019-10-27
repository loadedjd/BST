MAIN: bst.c main.c bst.h
	gcc -g -ansi -pedantic main.c bst.c -o MAIN

BST: bst.c bst.h
	gcc -g -ansi -pedantic bst.c -o BST

TEST: test.c bst.c bst.h
	gcc -g -ansi -pedantic test.c bst.c -o  TEST
