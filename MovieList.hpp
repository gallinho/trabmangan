#ifndef MOVIESLIST_HPP
#define MOVIESLIST_HPP
#include "Movies.hpp"
#include <vector>

class MovieList{

private:
vector <Movies> List;
void addMovie(const Movies& movie);


public:

MovieList(){};
void loadFromFile(const string& filename);
Movies bestScore();//falta
Movies oldest();//falta
Movies mostRentable();//falta
void printList() const;

};

#endif