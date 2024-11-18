output: main.o MovieList.o
	g++ main.o MovieList.o -o output

main.o: main.cpp
	g++ -c main.cpp

MovieList.o: MovieList.cpp MovieList.hpp
	g++ -c MovieList.cpp

clean:
	rm *.o output