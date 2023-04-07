clean: 
	rm -rf bin/

test: test.o stack.o
	gcc bin/test.o bin/stack.o -o bin/test -g

test.o: test.c
	mkdir -p bin/
	gcc test.c -c -o bin/test.o -g

stack.o: stack.c stack.h
	mkdir -p bin/
	gcc stack.c -c -o bin/stack.o -g