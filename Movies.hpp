#ifndef MOVIES_HPP
#define MOVIES_HPP
#include <string>
#include <vector>
#include <iostream>

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

   void printMovie() const
    {
        cout << "Titulo: "<<name << " | " << "Diretor:" <<director << " | "<<"Ano: " << year << " | "<<"País: " << country << " | " 
        "Genero: "<< genre << " | "<<"Score: " << score << " | " <<"Bilheteria: "<< profit << endl;
    }
};

#endif