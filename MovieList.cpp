#include "MovieList.hpp"
#include <fstream>

void MovieList::addMovie(const Movies& movie)
{
    List.push_back(movie);
}

void MovieList::loadFromFile(const string& filename)
{
    ifstream infile(filename);

    if(!infile); //throw

    for(int i = 0; i < 7; i++){
        while(0);
    }

}
Movies MovieList::bestScore(){}
Movies MovieList::oldest(){}
Movies MovieList::mostRentable(){}
void MovieList::printList(){}