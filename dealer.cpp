//dealer.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include "user.h"
#include "findNumberofCards.h"
#include "readScore.h"
#include "printBoard.h"
#include <unistd.h> // used for creating time delay when dealer draws cards
using namespace std;


/*
Purpose: provides logic for Dealer's moves and prints the board during the dealer's turn
Inputs:
  - dealerCards: string array of dealer's cards
  - deck: string array of deck of cards
  - topCardIndex: integer index of the 'next' card to be drawn from deck
  - dealerScore: current score of dealer
  - userScore: current score of user
  - wallet: user's wallet amount
  - currentBet: user's current bet
  - playerCards: string array of user's cards
Outputs:
  - prints the game board onto the console
  - returns arbitiary 0 values when to exit function
*/
int dealer(std::string dealerCards[], std::string deck[], int &topCardIndex,int &dealerScore, int userScore, int wallet,int currentBet, std::string playerCards[15], bool userfinished){
  // if user has 21 or above, then dealer's turn is over
  if (userScore > 21)  {
    system("clear");
    cout << char(27) << "[1m" << "                          DEALER'S TURN                                " << char(27) << "[0m" << endl;
    printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards),userScore,dealerScore, userfinished);
    cout << char(27) << "[1m" << "Dealer automatically wins because you went bust!" << char(27) << "[0m" << endl;
    return 0;
  }

  //dealer cannot hit if the score is less than 17
  else if (readScore(dealerCards) >= 17) {
    system("clear");
    cout << char(27) << "[1m" << "                          DEALER'S TURN                                " << char(27) << "[0m" << endl;
    printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards),userScore,dealerScore,userfinished);
    return 0;
  }

  // while dealer score less that 17, dealer must Hit
  while (readScore(dealerCards) < 17) {
    usleep(1500000);
    system("clear");
    cout << char(27) << "[1m" << "                          DEALER'S TURN                                " << char(27) << "[0m" << endl;
    dealerCards[findNumberofCards(dealerCards)] = deck[topCardIndex];
    topCardIndex += 1;
    dealerScore = readScore(dealerCards);
    printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards),userScore,dealerScore, userfinished);

  }

  return 0;
}
