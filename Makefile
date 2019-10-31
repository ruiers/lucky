CXX = g++

lucky:  lucky.o
	g++ -g -o lucky lucky.cpp

clean:
	-rm *.o lucky
