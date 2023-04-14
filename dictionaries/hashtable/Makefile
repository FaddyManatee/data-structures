testhash: testhash.o hashtable.o
	gcc bin/testhash.o bin/hashtable.o -o bin/testhash -g -lm

clean: 
	rm -rf bin/

testhash.o: testhash.c
	mkdir -p bin/
	gcc testhash.c -c -o bin/testhash.o -g

hashtable.o: hashtable.c hashtable.h
	mkdir -p bin/
	gcc hashtable.c -c -o bin/hashtable.o -g