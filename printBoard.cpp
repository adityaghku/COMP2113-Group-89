//printBoard.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "printDealerCards.h"
#include "printPlayerCards.h"
#include "numberofDigits.h"
using namespace std;

/*
Purpose:
Inputs:
  - x:
Outputs:
  - y:
*/
void printBoard(int wallet,int currentBet, string playerCards[15], string dealerCards[15], int playerCardsSize, int dealerCardsSize,int userScore, int dealerScore, bool userfinished){
  cout << setfill('-') << setw(72) << " " << endl;
  cout << setfill(' ');

  cout << "|" << setw(70) << "|" << endl;
  printDealerCards(dealerCardsSize, dealerCards, userfinished);
  cout << "|" << setw(70) << "|" << endl;

  cout << "|" << "                     Dealers Score: " << dealerScore;
  int l = 70 - 36 - numberofDigits(dealerScore);
  cout << setw(l) << "|" << endl;

  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      Wallet: " << "$" << wallet;
  l = 70 - 15 - numberofDigits(wallet);
  cout << setw(l) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      Bet Amount: " << "$" << currentBet;
  l = 70 - 19 - numberofDigits(currentBet);
  if (currentBet==0){
    l-=1;
  }

  cout << setw(l) << "|" << endl;

  cout << "|" << setw(70) << "|" << endl;

  cout << "|" << "                     Your Score: " << userScore;
  l = 70 - 33 - numberofDigits(userScore);
  cout << setw(l) << "|" << endl;

  printPlayerCards(playerCardsSize, playerCards);
  cout << "|" << setw(70) << "|" << endl;


  cout << setfill('-') << setw(72) << " " << endl;
}
