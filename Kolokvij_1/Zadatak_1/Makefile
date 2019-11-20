CC=g++
CFLAGS=-I.
DEPS = Statistics.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

zad1: zad1.o Statistics.o
	$(CC) -o zad1 zad1.o Statistics.o

clean:
	rm -rf *.o zad1
