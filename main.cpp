#include <iostream>
#include "MovieList.hpp"


int main(){

MovieList filmes;

filmes.loadFromFile("teste.txt");

filmes.printList();

}