//dealer.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "user.h"
#include "findNumberofCards.h"
#include "readScore.h"
using namespace std;

int dealer(std::string dealerCards[], std::string deck[], int &topCardIndex,int &dealerScore, int userScore){
  cout << "Dealer's cards: ";

  for (size_t i = 0; i < findNumberofCards(dealerCards); i++) {
    cout << dealerCards[i] << ", ";
  }
  // if user has 21 or above, then dealer's turn is over
  if (userScore > 21) return 0;

  // while dealer score less that 17, dealer must Hit
  while (readScore(dealerCards) < 17) {
    dealerCards[findNumberofCards(dealerCards)] = deck[topCardIndex];
    topCardIndex += 1;
    dealerScore = readScore(dealerCards);
    cout << endl << "dealer's cards: ";
    for (size_t i = 0; i < findNumberofCards(dealerCards); i++) {
      cout << dealerCards[i] << ", ";
    }
  }
}
