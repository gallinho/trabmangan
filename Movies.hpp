#ifndef MOVIES_HPP
#define MOVIES_HPP
#include <string>
#include <vector>

using namespace std;

class Movies
{

private:
    string name;
    string director;
    int year;
    string country;
    string genre;
    double score;
    int profit;

public:
    Movies() : name("Desconhecido"), director("Ninguém"), year(0), country("NULL"), genre("null"), score(0.0), profit(0) {};
   
    Movies(string name, string director, int year, string country, string genre,
           double score, int profit) : name(name), director(director),
                                       year(year), country(country), genre(genre), 
                                       score(score), profit(profit) {};
};

#endif