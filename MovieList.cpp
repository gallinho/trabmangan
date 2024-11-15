#include "MovieList.hpp"
#include "Movies.hpp"
#include <fstream>
#include <string>
using namespace std;

void MovieList::addMovie(const Movies& movie)
{
    List.push_back(movie);
}

void MovieList::loadFromFile(const string& filename)
{
    ifstream file(filename, ifstream::in); //nao tenho crtz se precisa do ifstream::in, mas vi na internet que o construtor pede
    
    string tmp;

    string name,director,country,genre;
    int year,profit;                     // nao gostei muito dessa parte
    double score;


    while(getline(file, tmp)){

       if (std::getline(file, name, ',') &&
        getline(file, director, ',') &&
        getline(file, country, ',') &&
        getline(file, genre, ',') &&
        getline(file, year, ',') &&
        getline(file, profit, ',') && /// vai dar errado, getline da std so funciona com string.
        getline(file, score, ',')
        )
        {
        Movies a(name, director, country, genre, year, profit, score);
        addMovie(a);
        }
        else cout<<"erro"<<endl; // fazer algum throw, pra aprender (e ganhar mais nota)
    }
}
Movies MovieList::bestScore(){}
Movies MovieList::oldest(){}
Movies MovieList::mostRentable(){}
void MovieList::printList() const
{
    for(int i = 0; i<2; i++){
        List[i].printMovie;
    }  
}