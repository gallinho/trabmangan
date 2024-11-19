#include <iostream>
#include <vector>
#include "MovieList.hpp"
#include <locale>
#include <string>

void header();
void choices();
void printgenres(string &aux);
void printcountries(string &aux);

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
        case 4:
            printcountries(aux);
            (filmes.bestPerCountry(aux)).printMovie();
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
              << "----------- 1 = Action                                       -----------" << endl
              << "----------- 2 = Adventure                                    -----------" << endl
              << "----------- 3 = Animation                                    -----------" << endl
              << "----------- 4 = Biographical                                 -----------" << endl
              << "----------- 5 = Comedy                                       -----------" << endl
              << "----------- 6 = Crime                                        -----------" << endl
              << "----------- 7 = Drama                                        -----------" << endl
              << "----------- 8 = Fantasy                                      -----------" << endl
              << "----------- 9 = Historical                                   -----------" << endl
              << "----------- 10 = Horror                                      -----------" << endl
              << "----------- 11 = Mystery                                     -----------" << endl
              << "----------- 12 = Psychological                               -----------" << endl
              << "----------- 13 = Romance                                     -----------" << endl
              << "----------- 14 = Science Fiction                             -----------" << endl
              << "----------- 15 = Suspense                                    -----------" << endl
              << "----------- -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= -----------" << endl
              << endl;

    int c;
    cout << "Enter the number corresponding to the gender you want: ";
    cin >> c;

    switch (c)
    {
    case 1:
        aux = "Ação";
        break;
    case 2:
        aux = "Aventura";
        break;
    case 3:
        aux = "Animação";
        break;
    case 4:
        aux = "Biografia";
        break;
    case 5:
        aux = "Comédia";
        break;
    case 6:
        aux = "Crime";
        break;
    case 7:
        aux = "Drama";
        break;
    case 8:
        aux = "Fantasia";
        break;
    case 9:
        aux = "Histórico";
        break;
    case 10:
        aux = "Terror";
        break;
    case 11:
        aux = "Mistério";
        break;
    case 12:
        aux = "Psicológico";
        break;
    case 13:
        aux = "Romance";
        break;
    case 14:
        aux = "Ficção Científica";
        break;
    case 15:
        aux = "Suspense";
        break;
    default:
        cout << "Please enter a valid gender." << endl;
        break;
    }
}


void printcountries(string &aux) {
    cout << "---------------------     COUNTRIES AVAILABLE     -------------------" << endl
              << "----------- 1 = EUA (Estados Unidos da América)               -----------" << endl
              << "----------- 2 = KOR (Coreia do Sul)                           -----------" << endl
              << "----------- 3 = BRA (Brasil)                                  -----------" << endl
              << "----------- 4 = FRA (França)                                  -----------" << endl
              << "----------- 5 = POL (Polônia)                                 -----------" << endl
              << "----------- 6 = ITA (Itália)                                  -----------" << endl
              << "----------- 7 = ESP (Espanha)                                 -----------" << endl
              << "----------- 8 = HUN (Hungria)                                 -----------" << endl
              << "-----------------------------------------------------------------------" << endl
              << endl;

    int c;
    cout << "Enter the number corresponding to the country you want: ";
    cin >> c;

    switch (c) {
    case 1:
        aux = "EUA";
        break;
    case 2:
        aux = "KOR";
        break;
    case 3:
        aux = "BRA";
        break;
    case 4:
        aux = "FRA";
        break;
    case 5:
        aux = "POL";
        break;
    case 6:
        aux = "ITA";
        break;
    case 7:
        aux = "ESP";
        break;
    case 8:
        aux = "HUN";
        break;
    default:
        cout << "Please enter a valid number." << endl;
        break;
    }
}
