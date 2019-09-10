CC = g++
INCLIBDIR = $(LIBHARU)/include
SRCLIBDIR = $(LIBHARU)/src/

LIBHARU = ./libharu

spiralPDF : spiralPDF.o Spiral.o HaruPDF.o Spiral.cpp
	$(CC) -o spiralPDF spiralPDF.o -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

spiralPDF.o : Spiral.o HaruPDF.o Spiral.cpp
	$(CC) -c spiralPDF.cpp -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

HaruPDF.o : $(INCLIBDIR)/hpdf.h Spiral.cpp Spiral.o
	$(CC) -c HaruPDF.cpp -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

Spiral.o : Spiral.cpp HaruPDF.o
	$(CC) -c Spiral.cpp -I$(INCLIBDIR) -L$(SRCLIBDIR) -lhpdfs

clean :
	rm spiralPDF *.o Spiral *.o HaruPDF* .o

test :
	./spiralPDF "Hello there. General Kenobi! This text just needs to be long"
