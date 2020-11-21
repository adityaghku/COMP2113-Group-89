//printBoard.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "printDealerCards.h"
#include "printPlayerCards.h"
#include "numberofDigits.h"
using namespace std;

/*
Purpose: To print out the entireboard
Inputs:
  - x: Takes in the wallet, bet, cards of player and dealer (plus the array sizes)
  the user score, and the dealer score to print. Also a boolean if the user has userfinished
  in order to show the dealers card or not
Outputs:
  - y: no return value, prints out a UI interface for the gameplay
*/
void printBoard(int wallet,int currentBet, string playerCards[15], string dealerCards[15], int playerCardsSize, int dealerCardsSize,int userScore, int dealerScore, bool userfinished){
  cout << setfill('-') << setw(72) << " " << endl; //border printing
  cout << setfill(' ');

  cout << "|" << setw(70) << "|" << endl;
  printDealerCards(dealerCardsSize, dealerCards, userfinished); //dealer cards printed
  cout << "|" << setw(70) << "|" << endl;

  if (userfinished){
    cout << "|" << "                     Dealers Score: " << dealerScore;
    int l = 70 - 36 - numberofDigits(dealerScore); // all calculations done for symmetricity and spacing
    cout << setw(l) << "|" << endl;
  }
  else{
    cout << "|" << "                     Dealers Score: ";
    int l = 70 - 36; // all calculations done for symmetricity and spacing
    cout << setw(l) << "|" << endl;
  }

  int l;

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

  printPlayerCards(playerCardsSize, playerCards); //usercards printed
  cout << "|" << setw(70) << "|" << endl;


  cout << setfill('-') << setw(72) << " " << endl;
}
