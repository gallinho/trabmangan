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
        string name, director, country, genre;
        double score;
        int year, profit;

        // Ler cada campo da linha separada por vírgula
        getline(streamline, name, ',');
        getline(streamline, director, ',');
        streamline >> year;
        streamline.ignore(1, ',');  // Ignorar vírgula
        getline(streamline, country, ',');
        getline(streamline, genre, ',');
        streamline >> score;
        streamline.ignore(1, ',');  // Ignorar vírgula
        streamline >> profit;

        // Criar o objeto Movies e adicionar à lista
        Movies movie(name, director, year, country, genre, score, profit);
        addMovie(movie);
    }

    file.close();
}

Movies MovieList::bestScore()
{
    Movies a; // Placeholder por enquanto
    return a;
}

Movies MovieList::oldest()
{
    Movies a; // Placeholder por enquanto
    return a;
}

Movies MovieList::mostRentable()
{
    Movies a; // Placeholder por enquanto
    return a;
}

void MovieList::printList() const
{
    for (const auto& movie : List)
    {
        movie.printMovie();
    }
}
