//printBoard.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "printDealerCards.h"
#include "printPlayerCards.h"
#include "numberofDigits.h"
using namespace std;

void printBoard(int wallet,int currentBet, string playerCards[15], string dealerCards[15], int playerCardsSize, int dealerCardsSize){
  cout << setfill('-') << setw(72) << " " << endl;
  cout << setfill(' ');

  cout << "|" << setw(70) << "|" << endl;
  printDealerCards(dealerCardsSize, dealerCards);
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      wallet: " << "$" << wallet;
  int l = 70 - 14 - numberofDigits(wallet);
  cout << setw(l) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      Bet Amount: " << "$" << currentBet;
  l = 70 - 19 - numberofDigits(currentBet);
  cout << setw(l) << "|" << endl;
  printPlayerCards(playerCardsSize, playerCards);
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;

  cout << setfill('-') << setw(72) << " " << endl;
}
