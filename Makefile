CC = g++ 
CFLAGS = -std=c++11 -Wall -Werror -pedantic 
LFLAGS = -lsfml-system -lsfml-audio -lsfml-window -lsfml-graphics

all: KSGuitarSim 

KSGuitarSim: CircularBuffer.o StringSound.o KSGuitarSim.o
	$(CC) -o $@ CircularBuffer.o StringSound.o KSGuitarSim.o $(LFLAGS)

KSGuitarSim.o: KSGuitarSim.cpp CircularBuffer.h StringSound.h
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp -o KSGuitarSim.o

CircularBuffer.o: CircularBuffer.cpp
	$(CC) $(CFLAGS) -c CircularBuffer.cpp -o CircularBuffer.o 

StringSound.o: StringSound.cpp 
	$(CC) $(CFLAGS) -c StringSound.cpp -o StringSound.o 

clean: 
	rm -f KSGuitarSim *.o