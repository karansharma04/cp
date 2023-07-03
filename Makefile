main: test1.o test2.o
	g++ -o test_output test1.o test2.o

test1.o: test1.cpp
	g++ -c test1.cpp

test2.o: test2.cpp
	g++ -c test2.cpp
