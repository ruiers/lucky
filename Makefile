CXX = g++

lucky:  lucky.o
	g++ -o lucky lucky.cpp

clean:
	-rm *.o lucky
