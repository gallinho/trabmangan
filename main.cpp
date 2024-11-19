#include <iostream>
#include <vector>
#include "MovieList.hpp"
#include <locale>
#include <string>

void header();
void choices();
void printgenres(string &aux);

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    MovieList filmes;

    filmes.loadFromFile("teste.txt");

    bool Bfim{false};

    header();

    while (!Bfim)
    {
        int c;
        choices();
        cin >> c;
        string aux;
       
        switch (c)
        {
        case 1:
            filmes.printList();
            break;
        case 2:
            (filmes.bestScore()).printMovie();
            break;
        case 3:
            printgenres(aux);
            (filmes.bestPerGenre(aux)).printMovie();
            break;
        case 4:;
            break;
        case 5:
            (filmes.oldest()).printMovie();
            break;
        case 6:
            (filmes.mostRentable()).printMovie();
            break;
        case 0:
            Bfim = true;
            break;
        }
    }

    return 0;
}

void header()
{

    cout << "-----------=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-----------" << endl
         << "------------------- WELCOME TO THE MOVIE TERMINAL -------------------" << endl
         << "----------- made by Bernardo P. Mendes and Lucas G. Gomes -----------" << endl
         << "------------            and Gustavo T. Gallo             ------------" << endl
         << "-----------=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-----------" << endl
         << endl;
}

void choices()
{
    cout << "-----------=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-----------" << endl
         << "-------------------      CHOOSE YOUR OPERATION     -------------------" << endl
         << "----------- 1 = Show all Movies                           -----------" << endl
         << "----------- 2 = Show the best Movie (IMDB)                -----------" << endl
         << "----------- 3 = Show the best movie from genre            -----------" << endl
         << "----------- 4 = Show the best movie per country           -----------" << endl
         << "----------- 5 = Show the oldest movie                     -----------" << endl
         << "----------- 6 = Show the most rentable movie              -----------" << endl
         << "----------- 0 = Exit                                      -----------" << endl
         << "-----------=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-----------" << endl
         << endl;
}

void printgenres(string &aux)
{

    cout << "---------------------     MOVIE GENRES AVAILABLE     -------------------" << endl
         << "----------- 7 = Action                                       -----------" << endl
         << "----------- 8 = Adventure                                    -----------" << endl
         << "----------- 9 = Animation                                    -----------" << endl
         << "----------- 10 = Biographical                                -----------" << endl
         << "----------- 11 = Comedy                                      -----------" << endl
         << "----------- 12 = Crime                                       -----------" << endl
         << "----------- 13 = Drama                                       -----------" << endl
         << "----------- 14 = Fantasy                                     -----------" << endl
         << "----------- 15 = Historical                                  -----------" << endl
         << "----------- 16 = Horror                                      -----------" << endl
         << "----------- 17 = Mystery                                     -----------" << endl
         << "----------- 18 = Psychological                               -----------" << endl
         << "----------- 19 = Romance                                     -----------" << endl
         << "----------- 20 = Science Fiction                             -----------" << endl
         << "----------- 21 = Suspense                                    -----------" << endl
         << "----------- -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= -----------" << endl
         << endl;

    int c;
    cout << "Digite o número correspondente ao gênero que você deseja: ";
    cin >> c;

    switch (c)
    {
    case 7:
        aux = "Ação";
        break;
    case 8:
        aux = "Aventura";
        break;
    case 9:
        aux = "Animação";
        break;
    case 10:
        aux = "Biografia";
        break;
    case 11:
        aux = "Comédia";
        break;
    case 12:
        aux = "Crime";
        break;
    case 13:
        aux = "Drama";
        break;
    case 14:
        aux = "Fantasia";
        break;
    case 15:
        aux = "Histórico";
        break;
    case 16:
        aux = "Terror";
        break;
    case 17:
        aux = "Mistério";
        break;
    case 18:
        aux = "Psicológico";
        break;
    case 19:
        aux = "Romance";
        break;
    case 20:
        aux = "Ficção Científica";
        break;
    case 21:
        aux = "Suspense";
        break;
    default:
        cout << "Opção inválida! Por favor, selecione um gênero válido." << endl;
        break;
    }
}
