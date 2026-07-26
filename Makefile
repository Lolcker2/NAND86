out: main.o stack.o macro.o dstring.o
	gcc build\main.o build\stack.o build\macro.o build\dstring.o -o out.exe

main.o: src\main.c 
	gcc -c src\main.c -o build\main.o

stack.o: src\stack.c
	gcc -c src\stack.c -o build\stack.o

macro.o: src\macro.c
	gcc -c src\macro.c -o build\macro.o

dstring.o: src\dstring.c
	gcc -c src\dstring.c -o build\dstring.o