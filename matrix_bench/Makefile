
PROG = bench
CC = g++
CPPFLAGS = -g -Wall
OBJS = bench_func.o matrix.o main_bench.o
LIBS = -lblas

$(PROG): $(OBJS)
		$(CC) $(CPPFLAGS) bench_func.o matrix.o main_bench.o  -o $(PROG) $(LIBS)
matrix.o: matrix.h
		$(CC) $(CPPFLAGS) -c matrix.cpp
bench_func.o: bench_func.h
		$(CC) $(CPPFLAGS) -c bench_func.cpp
main_bench.o:
	 	$(CC) $(CPPFLAGS) -c main_bench.cpp

clean:
		rm -f core $(PROG) $(OBJS)
