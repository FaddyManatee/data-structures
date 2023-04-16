test: test.o queue.o
	gcc bin/test.o bin/queue.o -o bin/test -g

clean: 
	rm -rf bin/

test.o: test.c
	mkdir -p bin/
	gcc test.c -c -o bin/test.o -g

queue.o: queue.c queue.h
	mkdir -p bin/
	gcc queue.c -c -o bin/queue.o -g