clean: 
	rm -rf bin/

test: test.o dlinkedlist.o
	gcc bin/test.o bin/dlinkedlist.o -o bin/test -g

test.o: test.c
	mkdir -p bin/
	gcc test.c -c -o bin/test.o -g

dlinkedlist.o: dlinkedlist.c dlinkedlist.h
	mkdir -p bin/
	gcc dlinkedlist.c -c -o bin/dlinkedlist.o -g