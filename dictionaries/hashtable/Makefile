test: test.o hashtable.o
	gcc bin/test.o bin/hashtable.o -o bin/test -g -lm

clean: 
	rm -rf bin/

test.o: test.c
	mkdir -p bin/
	gcc test.c -c -o bin/test.o -g

hashtable.o: hashtable.c hashtable.h
	mkdir -p bin/
	gcc hashtable.c -c -o bin/hashtable.o -g