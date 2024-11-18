output: main.o MoviesList.o
	g++ main.o MoviesList.o -o output

main.o: main.cpp
	g++ -c main.cpp

MoviesList.o: MoviesList.cpp MoviesList.hpp
	g++ -c MoviesList.cpp

clean:
	rm *.o output