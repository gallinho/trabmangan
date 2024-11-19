#ifndef MOVIES_HPP
#define MOVIES_HPP
#include <string>
#include <vector>
#include <iostream>
#include <locale>
#include <iomanip>
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
    
        std::setlocale(LC_ALL,"Portuguese");
               std::setlocale(LC_ALL,"Portuguese");

        cout << left << setw(45) << name 
                     << setw(45) << director 
                     << setw(6) << year 
                     << setw(15) << country 
                    << setw(35) << (genre1 + "/" + genre2) 
                    << setw(8) << score 
                     << profit << endl;

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