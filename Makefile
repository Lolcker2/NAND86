out: main.o stack.o
	gcc build\main.o build\stack.o -o out.exe

main.o: src\main.c 
	gcc -c src\main.c -o build\main.o

stack.o: src\stack.c
	gcc -c src\stack.c -o build\stack.o