#include <iostream>
#include <vector>
#include "MovieList.hpp"

using namespace std;
int main(){

MovieList filmes;

filmes.loadFromFile("teste.txt");

//filmes.printList();

//(filmes.bestScore()).printMovie();
//(filmes.mostRentable()).printMovie();
//(filmes.oldest()).printMovie();
(filmes.bestPerCountry("KOR")).printMovie(); // ta dando erro aqui
(filmes.bestPerGenre("Drama")).printMovie();




}