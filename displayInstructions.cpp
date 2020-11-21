//displayInstructions.cpp

#include <iostream>
#include "displayInstructions.h"
using namespace std;

/*
What it does: print instructions for the game
Inputs:
- none
Outputs:
  - instructions of the game
*/
void displayInstructions() {
  cout << endl;
  cout << "Blackjack is a game where the player plays against the dealer, choosing their own bet amount to try and win as much money as possible against the casino." << endl << endl;
  cout << char(27) << "[1m" << "Game Rules:" << char(27) << "[0m" << endl << endl;
  cout << "• The aim of the game is to try to beat the dealer without going bust." << endl;
  cout << "• Numbered cards are worth their actual value, face cards are all worth 10, and Aces are worth either 1 or 11, whichever leads to a better hand." << endl;
  cout << "• If the sum of the values of the players cards exceeds 21, they go 'bust' and automatically lose the round." << endl;
  cout << "• You can either Hit or Stand on each turn. If you hit then you receive another card. If you stand, you do not want more cards and the round is over." << endl;
  cout << "• You can also choose to Double. If you double, then you double your original bet, but can only receive one more card." << endl;
  cout << "• If you receive an Ace and a face card as your first two cards, then you have received Blackjack and you automatically receive your bet plus 1.5 times your bet back." << endl;
  cout << "• After you stand, it is now the dealers turn." << endl;
  cout << "• The dealer will hit until their score is 17 or higher, after which they will stand." << endl;
  cout << "• The winner of the round is the individual with the score closest to 21, but not more than 21." << endl;
  cout << "• If you win a round normally, you receive your original bet plus an amount equal to your original bet back." << endl;
}
