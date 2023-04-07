test: test.o arraylist.o
	gcc bin/test.o bin/arraylist.o -o bin/test -g

clean: 
	rm -rf bin/

test.o: test.c
	mkdir -p bin/
	gcc test.c -c -o bin/test.o -g

arraylist.o: arraylist.c arraylist.h
	mkdir -p bin/
	gcc arraylist.c -c -o bin/arraylist.o -g