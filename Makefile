CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage 


all: catchdebug  catchdebug2 keygen encrypt  decrypt

ReallyLongInt.o:  ReallyLongInt.cpp  ReallyLongInt.hpp
	$(CC) -c  ReallyLongInt.cpp

numberTheory.o: numberTheory.cpp numberTheory.hpp
	$(CC) -c numberTheory.cpp


catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGS) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp  ReallyLongInt.o

catchdebug2: numberTheory.o   ReallyLongInt.o numberTheory_TEST.cpp
	$(CC) $(CFLAGS) -o numberTheory_TEST numberTheory.o  ReallyLongInt.o numberTheory_TEST.cpp 

coverage:  ReallyLongInt_TEST.cpp  ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(COVERAGE) ReallyLongInt_TEST.cpp  ReallyLongInt.cpp

keygen: ReallyLongInt.o  numberTheory.o keygen.cpp
	$(CC) -o keygen ReallyLongInt.o  numberTheory.o keygen.cpp

encrypt: ReallyLongInt.o encrypt.cpp
	$(CC) -o encrypt  ReallyLongInt.o encrypt.cpp

decrypt: ReallyLongInt.o decrypt.cpp
	$(CC) -o decrypt  ReallyLongInt.o decrypt.cpp


clean:
	rm *.o; rm ReallyLongInt_TEST; 


