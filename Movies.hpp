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
    string genre1;
    string genre2;
    double score;
    int profit;

public:
    Movies() : name("Desconhecido"), director("Ninguém"), year(0), country("NULL"), genre1("null"), genre2("null"), score(0.0), profit(0) {};
   
    Movies(string name, string director, int year, string country, string genre1, string genre2,
           double score, int profit) : name(name), director(director),
                                       year(year), country(country), genre1(genre1), genre2(genre2),
                                       score(score), profit(profit) {};

   void printMovie() const
    {
        cout << "Titulo: "<<name << " | " << "Diretor:" <<director << " | "<<"Ano: " << year << " | "<< endl 
        <<"País: " << country << " | "  "Generos: "<< genre1 << "/"<<genre2 << " | "<<"Score: " << score << " | " <<"Bilheteria: "<< profit << endl << endl;
    }

    int getProfit() const
    {
        return profit;
    }

    double getScore() const
    {
        return score;
    }

    int getYear() const 
    {
        return year;
    }
    
    string getGenre1() const 
    {return genre1;}
    
    string getGenre2() const 
    {return genre2;}

    string getCountry() const 
    {
        return country;
    }
};

#endif