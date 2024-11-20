#include "MovieList.hpp"
#include "Movies.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void MovieList::addMovie(const Movies &movie)
{
    List.push_back(movie);
}

void MovieList::loadFromFile(const string &filename)
{
    ifstream file(filename); // criamos objeto da classe ifstream usando o construtor parametrizado para abrir o arquivo.

    if (!file.is_open()) // verifica se o arquivo foi aberto corretamente
    {
        throw runtime_error("Erro ao abrir o arquivo: " + filename); 
    }

    string line;
    while (getline(file, line))  //retira uma linha do arquivo e armazena na variavel do tipo string "line"
    {
        stringstream streamline(line); //cria um objeto da classe stringstream e armazena a linha nele

        string name, director, country, genre1, genre2; //
        double score;                                   // variaveis auxiliares
        int year, profit;                               //

        // ler cada campo da linha separada por virgula e adicionar na variavel auxiliar
        getline(streamline, name, ',');        //pegamos a informacao do arquivo usando getline com 
        getline(streamline, director, ',');
        streamline >> year;
        streamline.ignore(1, ','); // Ignorar virgula
        getline(streamline, country, ',');
        getline(streamline, genre1, ',');
        getline(streamline, genre2, ',');
        streamline >> score;
        streamline.ignore(1, ','); 
        streamline >> profit;

        // criar o objeto Movies e adicionar a lista usando as variaveis como parametros
        Movies movie(name, director, year, country, genre1, genre2, score, profit);
        addMovie(movie); // coloca o movie criado na lista
    }

    file.close(); // fecha o arquivo
}

Movies MovieList::bestScore()
{
    if(List.empty()) throw runtime_error("Lista vazia!");


    Movies bestScore = List[0];
  

    for (const auto &movie : List)
    {
        if (movie.getScore() > bestScore.getScore())
        {
            bestScore = movie;
        }
    }

    return bestScore;
}

Movies MovieList::oldest()
{
    if(List.empty()) throw runtime_error("Lista vazia!");

    Movies oldest = List[0];
   
    for (const auto &movie : List)
    {
        if (movie.getYear() < oldest.getYear())
        {
            oldest = movie;
        }
    }

    return oldest;
}

Movies MovieList::mostRentable()
{
    if(List.empty()) throw runtime_error("Lista vazia!");


    Movies MostR = List[0];
  

    for (const auto &movie : List) // Itera pelo vetor verificando qual o filme mais rentável e retorna o mesmo
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
  
    if (List.empty())
    {
        throw runtime_error("Lista vazia"); //verifica se a lista esta vazia
    }

    const Movies *best = nullptr; //cria um *movie com nullptr para evitar erros

    for (const auto &movie : List)  // usa laço de for com iterador para percorrer a lista evitando copias
    {
        if (movie.getGenre1() == genre || movie.getGenre2() == genre) //verifica se o filme é do genero escolhido
        {
            if (best == nullptr || movie.getScore() > best->getScore()) //compara as notas do best com o filme atual
            {
                best = &movie;  
            }
        }
    }

    if (best == nullptr)    //caso best fique com nullptr, não existe nenhum filme com o genero escolhido
    {
        throw runtime_error("Nenhum filme com esse genero");
    }

    return *best;
}

Movies MovieList::bestPerCountry(string country){
    if (List.empty())
    {
        throw runtime_error("Lista vazia");
    }

    const Movies *best = nullptr;

    for (const auto &movie : List)
    {
        if (movie.getCountry() == country)
        {
            if (best == nullptr || movie.getScore() > best->getScore())
            {
                best = &movie;
            }
        }
    }

    if (best == nullptr)
    {
        throw runtime_error("Nenhum filme desse país");
    }

    return *best;
}

void MovieList::printList() const
{

    if (List.empty())
    {
        throw runtime_error("LISTA ESTA VAZIA!!!");
    }
    cout << endl;
    // Cabeçalho da tabela
    cout << left << setw(45) << "Title" //setW define a largura
         << setw(45) << "Director"
         << setw(6) << "Year"
         << setw(15) << "Country"
         << setw(35) << "Genre"
         << setw(8) << "Score"
         << "Profit M/DOL" << endl;

    cout << string(170, '-') << endl; // Linha divisória

    for (const auto &movie : List)
    {
        movie.printMovie();
    }

    cout << string(170, '-') << endl
         << endl; // Linha divisória
}

int MovieList::size() const
{
    return distance(List.begin(), List.end());
}