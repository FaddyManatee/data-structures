clean: 
	rm -rf bin/

test: test.o linkedlist.o
	gcc bin/test.o bin/linkedlist.o -o bin/test -g

test.o: test.c
	mkdir -p bin/
	gcc test.c -c -o bin/test.o -g

linkedlist.o: linkedlist.c linkedlist.h
	mkdir -p bin/
	gcc linkedlist.c -c -o bin/linkedlist.o -g