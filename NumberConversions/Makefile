CFLAGS =-std=c++11 -g

all: bin2dec dec2bin

bin2dec: bin2dec.o
	g++ bin2dec.o -o bin2dec

bin2dec.o: bin2dec.cpp
	g++ ${CFLAGS} -c bin2dec.cpp

dec2bin: dec2bin.o
	g++ dec2bin.o -o dec2bin

dec2bin.o: dec2bin.cpp
	g++ ${CFLAGS} -c dec2bin.cpp

clean:
	rm *.o

cleanall: clean
	rm bin2dec dec2bin
