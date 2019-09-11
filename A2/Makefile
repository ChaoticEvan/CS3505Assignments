CC = g++
INCLIBDIR = $(LIBHARU)/include
SRCLIBDIR = $(LIBHARU)/src/

LIBHARU = ./libharu

spiralPDF : spiralPDF.o HaruPDF.o Spiral.o
	$(CC) -o spiralPDF spiralPDF.cpp Spiral.cpp -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

spiralPDF.o : Spiral.o
	$(CC) spiralPDF.cpp Spiral.cpp -o spiralPDF.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

HaruPDF.o : $(INCLIBDIR)/hpdf.h HaruPDF.o
	$(CC) -c HaruPDF.cpp -o HaruPDF.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

Spiral.o : Spiral.o HaruPDF.o HaruPDF.cpp HaruPDF.h
	$(CC) -c Spiral.cpp -o Spiral.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

clean :
	rm spiralPDF *.o Spiral *.o HaruPDF* .o

test :
	./spiralPDF "Hello there. General Kenobi! This text just needs to be long"
