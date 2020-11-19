#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h> // for Random Number Generation
#include <ctime> // for Random Number Generation
#include "displayInstructions.h"
#include "winner.h"
#include "readScore.h"
#include "findNumberofCards.h"
#include "user.h"
#include "dealer.h"
#include "printBoard.h"
using namespace std;

//class.cpp
class playerData{
  public:
    string name;
    int wallet = 100;
    string key = "12sdas";

    // fun stats
    int wins;
    int gamesPlayed;
    int winPercentage;
};

//general

int main(){

//------------------------------INSTRUCTIONS --------------------------------------------

  cout << "Do you want to view the instructions? Y or N" << endl; //Instructions
  char instructions;
  cin >> instructions;
  if(instructions=='Y'){
    displayInstructions();
  }

  cout << "Begin game" << endl;

  //------------------------------SET UP GAME --------------------------------------------

  bool mainGameLoop = true; // the boolean variable for the game to continue
  bool didYouWin = false; // if player won previous round
  int wallet = 100;
  int currentBet;
  int userScore, dealerScore; // declare the userScore and dealerScore variables, which will be updated every round
  const string SEPERATOR = ""; // I will use this to store each indiv card and make it more readable - e.g. 7 + SEPERATOR + H refers to 7 of Hearts


  playerData P = { };

  string playerCards[15], dealerCards[15] = {}; // make array of user cards and dealer cards

//------------------------------LOAD GAME FUNCTIONALITY START--------------------------------------------

// SEE BOTTOM OF THIS DOC

//------------------------------LOAD GAME FUNCTIONALITY END--------------------------------------------


  //------------------------------GAME START--------------------------------------------
  while(mainGameLoop){
    cout << "How much do you want to bet (in an increment of 10)" << endl; //bet amount
    cin >> currentBet;
    wallet -= currentBet; //for user board display

    for(int i = 0; i < 15; i++) { // initialize the array of playerCards and dealerCards
        playerCards[i].clear();
        dealerCards[i].clear();
      }
    // -------CREATE DECK OF CARDS ------------
    string deck[52]; //a deck of cards
    string suits[4] = {"\u2764","\u2660","\u25C6", "\u2663"}; // ASCII characters for the 4 different suits
    string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    for (size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 13; j++) {
        deck[13*i + j] = ranks[j] + SEPERATOR + suits[i];
      }
    }

    // -------SHUFFLE THIS DECK OF CARDS ------------
    string holderString;
    int randomIndex;
    srand(time(NULL));
    for (size_t i = 0; i < 52; i++) {
      randomIndex = rand() % 52;
      holderString = deck[i];
      deck[i] = deck[randomIndex];
      deck[randomIndex] = holderString;
    }
    // for (size_t i = 0; i < 52; i++) {
    //   cout << deck[i] << endl;
    // }

    // -------DEAL CARDS -----------------------
    playerCards[0] = deck[0]; // user gets dealt 2 cards
    playerCards[1] = deck[1];
    dealerCards[0] = deck[2]; // dealer gets dealt 2 cards
    dealerCards[1] = deck[3];

    int topCardIndex = 4; // the next card to be dealt will be on index = 4 in the deck array

    // -------DEAL CARDS -----------------------
    printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards)); //Prints table for user visual appeal

    userScore = readScore(playerCards);
    dealerScore = readScore(dealerCards);
    if (readScore(playerCards) == 21){ //checking if the player has blackjack
      wallet+=2.5*currentBet;
      cout << "You have blackjack" << endl;
      printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards));
      didYouWin=true;
    }
    else {
      // -------USER MOVE -----------------------
      bool continueUserTurn = true;
      while (continueUserTurn){ // user turn continues until function returns false

        continueUserTurn = user(playerCards,deck,topCardIndex,userScore, currentBet, wallet);
        printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards));
      }
      for (size_t i = 0; i < findNumberofCards(playerCards); i++) {
        cout << playerCards[i] << ", ";
      }
      cout << endl << "Your final score: " << userScore << endl << endl;

      // -------DEALER MOVE -----------------------
      dealer(dealerCards, deck, topCardIndex, dealerScore, userScore); // dealer's turn
      cout << endl << "Dealer's score: " << dealerScore << endl;
      printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards));
    }

    // ------- Check winner -----------------------
    winner(userScore, dealerScore, wallet, currentBet);

    // ------- Update database -----------------------
    // updateUsers(playerdata); //update users.txt

    // -------Wallet balance check -----------------------

    if(wallet <= 0){
      cout << "You have no more money left, you lose" << endl; //Money check condition
      mainGameLoop = false;
    }

    // -------Play again check -----------------------
    cout << "Do you want to continue playing? Input Y or N" << endl; // Round playing
    char continueGame;
    cin >> continueGame;
    if(continueGame=='N'){
      mainGameLoop=false;
    }
  }
  // ------- Provide user's with key (given they have money to play again)-----------------------
  if(wallet!=0){
    cout << P.key << " is the key" << endl;
  }

  return 0;
}

//------------------------------LOAD GAME FUNCTIONALITY START--------------------------------------------

  //cout << "Load game or New?" << endl; //Load Game or New Game
  //string choice;
  //cin >> choice;

  //if (choice == "Load"){
    //cout << "Please enter your key: " << endl;
    //string inputkey;
    //cin >> inputkey;
    //loadGame(inputkey);
  //}

  //else{
    //cout << "What is your name?" << endl;
    //cin >> name; //Initialise the Cash, name, and key

    //generateKey(&key) //Make key only alphabets for simplicity

  //  cout << "How much money do you want to buy-in?" << endl;
  //  cin >> wallet;

  //  playerData playerdata[i] = {name, wallet, key};
//  }

//------------------------------LOAD GAME FUNCTIONALITY END--------------------------------------------
