//findNumberofCards.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "findNumberofCards.h"
using namespace std;

/*
Purpose: find the number of cards in a given array (of cards)
Inputs:
  - cards: a string array with each element representing a card, empty elements represent no cards
Outputs:
  - numberofCards: the number of cards in the array
*/

int findNumberofCards(string cards[]){

  int numberofCards = 0;

  while (!(cards[numberofCards].empty())) {
    numberofCards++;
  }
  
  return numberofCards;
}
