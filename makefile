make:	main.c func.c func.h
	gcc -Wall main.c func.c -o main

test:	test.c func.c func.h	
	gcc -Wall test.c func.c -o test
