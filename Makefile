HEADERS = TCB.h thread.h q.h

default: proj1

proj1.o: thread_test.c $(HEADERS)
	gcc -c thread_test.c -o proj1.o

proj1: proj1.o
	gcc proj1.o -o proj1

clean:
	-rm -f proj1.o
	-rm -f proj1
