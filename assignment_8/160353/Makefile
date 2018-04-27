CC=gcc
CFLAGS= -g -I. -DDBG
LDFLAGS= -lpthread -lm


all: cs251.ex1
	python run.py
	gnuplot scatter_t1.p
	gnuplot scatter_t2.p
	gnuplot scatter_t3.p
	gnuplot scatter_t4.p
	gnuplot scatter_t5.p
	python part_c.py
	gnuplot plot_speedup.p
	gnuplot plot_speedup_d.p
	pdflatex latex.tex


cs251.ex1: build 

build: app

app: prog.o thread_function.o 
	$(CC) prog.o thread_function.o common.h $(CFLAGS) $(LDFLAGS) -o app

prog.o: prog.c common.h
	$(CC) -c prog.c common.h $(CFLAGS)  

thread_function.o: thread_function.c common.h
	$(CC) -c thread_function.c common.h $(CFLAGS)



clean:
	rm -f *.o ccs251.ex1
