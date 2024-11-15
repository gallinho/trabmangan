#include "MovieList.hpp"
#include "Movies.hpp"
#include <fstream>
#include <string>
using namespace std;

void MovieList::addMovie(const Movies& movie)
{
    List.push_back(movie);
}

vector<Movies> MovieList::loadFromFile(const string& filename)
{
    vector<Movies> filmes;

    ifstream infile(filename, ifstream::in);

    string tmp;

    string name,director,country,genre;
    int year,profit;
    double score;


    while(getline(infile, tmp)){

       if (getline(infile, name, ',') &&
        getline(infile, director, ',') &&
        getline(infile, country, ',') &&
        getline(infile, genre, ',') &&

        /*getline(infile, year, ',') &&
        getline(infile, profit, ',') && /// vai dar errado, getline da std so funciona com string.
        getline(infile, score, ',')*/ 
        )
        {
        Movies a(name, director, country, genre, year, profit, score);
        filmes.push_back(a);
        }
        else throw; // fazer algum throw, pra aprender (e ganhar mais nota)
    }

    return filmes;
}
Movies MovieList::bestScore(){}
Movies MovieList::oldest(){}
Movies MovieList::mostRentable(){}
void MovieList::printList(){}