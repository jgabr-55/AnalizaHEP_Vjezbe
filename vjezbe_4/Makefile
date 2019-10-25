CC=g++
CFLAGS=-I.
DEPS = Analyzer.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

analyse: analyse.o Analyzer.o
	$(CC) -o analyse analyse.o Analyzer.o

clean:
	rm -rf *.o analyse
