#include "MovieList.hpp"
#include "Movies.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void MovieList::addMovie(const Movies &movie)
{
    List.push_back(movie);
}

void MovieList::loadFromFile(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        throw runtime_error("Erro ao abrir o arquivo: " + filename);
    }

    string line;
    while (getline(file, line))
    {
        stringstream streamline(line);
        string name, director, country, genre1, genre2;
        double score;
        int year, profit;

        // Ler cada campo da linha separada por vírgula
        getline(streamline, name, ',');
        getline(streamline, director, ',');
        streamline >> year;
        streamline.ignore(1, ',');  // Ignorar vírgula
        getline(streamline, country, ',');
        getline(streamline, genre1, ',');
        getline(streamline, genre2, ',');
        streamline >> score;
        streamline.ignore(1, ',');  // Ignorar vírgula
        streamline >> profit;

        // Criar o objeto Movies e adicionar à lista
        Movies movie(name, director, year, country, genre1, genre2, score, profit);
        addMovie(movie);
    }

    file.close();
}

Movies MovieList::bestScore()
{
      Movies bestScore = List[0];

    for(const auto& movie : List){
        if(movie.getScore()>bestScore.getScore())
         {
            bestScore = movie;
         }
         
    }

    return bestScore;
}

Movies MovieList::oldest()
{
    Movies oldest = List[0];

    for(const auto& movie : List){
        if(movie.getYear()<oldest.getYear())
         {
            oldest = movie;
         }
    }

    return oldest;
}

Movies MovieList::mostRentable()
{
    Movies MostR = List[0];

    for (const auto& movie : List) // Itera pelo vetor verificando qual o filme mais rentável e retorna o mesmo
    {
        if (movie.getProfit() > MostR.getProfit())
        {
            MostR = movie;
        }
    }

    return MostR;
}

Movies MovieList::bestPerGenre(string genre)
{
    if (List.empty()) {
        throw runtime_error("The list is empty.");
    }
    Movies best = List[0];

    for( const auto & movie : List){
        if(genre == movie.getGenre1() || genre == movie.getGenre2()){
            if (movie.getScore() > best.getScore())
            {
                best = movie;
            }
        }
    }


    return best;
}

Movies MovieList::bestPerCountry(string country) // não consegui 
{
    Movies best = List[0];

    for( const auto & movie : List){
        if(country == movie.getCountry()){
            if (movie.getScore() > best.getScore())
            {
                best = movie;
            }
        }
    }


    return best;
}

void MovieList::printList() const
{
    for (const auto& movie : List)
    {
        movie.printMovie();
    }
}
