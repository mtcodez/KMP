CXX=g++
CXXFLAGS= -g -Wall

all: test 

test: test.cpp M_KMP.o

M_KMP.o: M_KMP.cpp

clean:
	rm kmp *.o -f
