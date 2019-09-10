CC = g++
INCLIBDIR = $(LIBHARU)/include
SRCLIBDIR = $(LIBHARU)/src/

LIBHARU = ./libharu

spiralPDF : spiralPDF.o Spiral.o HaruPDF.o Spiral.cpp
	$(CC) -o spiralPDF spiralPDF.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

spiralPDF.o : Spiral.o HaruPDF.o Spiral.cpp
	$(CC) -c spiralPDF.cpp -o spiralPDF.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

HaruPDF.o : $(INCLIBDIR)/hpdf.h Spiral.cpp
	$(CC) -c HaruPDF.cpp -o HaruPDF.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

Spiral.o : Spiral.cpp HaruPDF.o
	$(CC) -c Spiral.cpp -o Spiral.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

clean :
	rm spiralPDF *.o Spiral *.o HaruPDF* .o

test :
	./spiralPDF "Hello there. General Kenobi! This text just needs to be long"
