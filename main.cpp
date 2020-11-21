#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
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
#include "saveload.h"
using namespace std;


int main(){

  system("clear"); //to improve UI experience
//------------------------------INSTRUCTIONS --------------------------------------------
  cout << R"(
        .------..------..------..------..------.     .------..------..------..------.
        |B.--. ||L.--. ||A.--. ||C.--. ||K.--. |.-.  |J.--. ||A.--. ||C.--. ||K.--. |
        | :(): || :/\: || (\/) || :/\: || :/\: ((5)) | :(): || (\/) || :/\: || :/\: |
        | ()() || (__) || :\/: || :\/: || :\/: |'-.-.| ()() || :\/: || :\/: || :\/: |
        | '--'B|| '--'L|| '--'A|| '--'C|| '--'K| ((1)) '--'J|| '--'A|| '--'C|| '--'K|
        `------'`------'`------'`------'`------'  '-'`------'`------'`------'`------'
        )" << endl;

  while(true) { //Invalid user input loop
    cout << char(27) << "[1m" << "Welcome to Blackjack by Aayush Batwara and Aditya Gupta!"<< char(27) << "[0m" << endl << endl;

    cout << char(27) << "[1m" << "Do you want to view the instructions? Y or N" << char(27) << "[0m" << endl;

    char instructions;
    cin >> instructions;

    if(instructions == 'Y'){
      displayInstructions();

      cout << endl << char(27) << "[1m" << "Enter any key to continue: " << char(27) << "[0m" << endl;

      string anyKey;
      cin >> anyKey;

      break;
    }

    else if(instructions == 'N'){
      break;
    }

    else {
      cout << "Invalid Input." << endl;
    }

  }

  system("clear");
  cout << endl << char(27) << "[1m" << "Let's begin the game!" << char(27) << "[0m" << endl << endl;


  //------------------------------SET UP GAME --------------------------------------------

  bool mainGameLoop = true; // the boolean variable for the game to continue
  bool didYouWin = false; // if player won previous round
  bool blackjack = false; // boolean variable for if the player won via Blackjack
  bool userfinished = false; // decide whether to show the dealers cards or not
  int wallet;
  int currentBet;
  int userScore, dealerScore; // declare the userScore and dealerScore variables, which will be updated every round
  const string SEPERATOR = ""; // I will use this to store each indiv card and make it more readable - e.g. 7 + SEPERATOR + H refers to 7 of Hearts

  string filename = "users.txt"; //since only one file is used, no need to change the name

  int arrayofPlayers_size = 3; //initial size of array
  playerData *arrayofPlayers = new playerData[arrayofPlayers_size]; //pointer of type playerData which is a Class. This will be used for file IO
  int numberofPlayers = 0;
  int currentplayer = 0;

  string playerCards[15], dealerCards[15] = {}; // make array of user cards and dealer cards

//------------------------------LOAD GAME FUNCTIONALITY START--------------------------------------------

  while (true){ //Invalid user input loop

    numberofPlayers = load_data(arrayofPlayers, arrayofPlayers_size);

    cout  << char(27) << "[1m" << "Do you want to load an old game? Y or N." << char(27) << "[0m" << endl;

    char loadgame;
    cin >> loadgame;

    if(loadgame == 'Y'){

      bool successfullload = false;

      while (true){
        cout << char(27) << "[1m" << "Please enter your key: " << char(27) << "[0m" << endl;

        string key_input;
        cin >> key_input;

        for (int i = 0; i < numberofPlayers; i++){
          if (arrayofPlayers[i].key == key_input){
            currentplayer = i;
            successfullload = true;
          }
        }

        if (successfullload){
          break;
        }

        else{
          cout << "Invalid Key." << endl;
        }
      }

      cout << "Enter any key to continue to your turn: " << endl;

      string anyKey;
      cin >> anyKey;

      break;

    }

    if(loadgame == 'N'){
      system("clear");

      addUser(arrayofPlayers, numberofPlayers, arrayofPlayers_size);

      currentplayer = numberofPlayers - 1;

      break;
    }

    else {cout << "Invalid Input." << endl;}
  }

//------------------------------LOAD GAME FUNCTIONALITY END--------------------------------------------


  //------------------------------GAME START--------------------------------------------
  wallet = arrayofPlayers[currentplayer].wallet; //initialise money

  while(mainGameLoop){

    if (wallet == 0){ //prevents game-breaking input from user
      mainGameLoop = false;
      cout << "You have no more money left, you lose" << endl;
    }

    system("clear");

    while (true){ // get the bet amount and avoid invalid user input
      cout << char(27) << "[1m" << "Welcome " << arrayofPlayers[currentplayer].name << char(27) << "[0m" << endl;
      cout << char(27) << "[1m" << "How much do you want to bet this round? Please enter a positive integer" << char(27) << "[0m" << endl;
      cout << char(27) << "[1m" << "Current wallet balance: " << wallet << char(27) << "[0m" << endl;

      cin >> currentBet;

      if (currentBet > wallet) cout << char(27) << "[1m" << "Insufficient balance. Please bet a lower amount." << char(27) << "[0m" << endl<< endl;
      else if (currentBet <= 0) cout << char(27) << "[1m"  << "Please enter a positive integer as the bet amount" << char(27) << "[0m" << endl << endl;
      else {break;}

    }

    wallet -= currentBet; //to display current wallet accurately on screen

    cout << endl << char(27) << "[1m" << "Your bet amount is $" << currentBet << endl << "Enter any key to continue to your turn: " << char(27) << "[0m" << endl;

    string anyKey;
    cin >> anyKey;

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

    // -------DEAL CARDS -----------------------
    playerCards[0] = deck[0]; // user gets dealt 2 cards
    playerCards[1] = deck[1];
    dealerCards[0] = deck[2]; // dealer gets dealt 2 cards
    dealerCards[1] = deck[3];

    int topCardIndex = 4; // the next card to be dealt will be on index = 4 in the deck array

    // -------GAMEPLAY BEGINS -----------------------
    userScore = readScore(playerCards);
    dealerScore = readScore(dealerCards);

    system("clear");

    blackjack = false;
    userfinished = false;

    // ------CHECK FOR BLACKJACK--------------------------
    if (readScore(playerCards) == 21){
      cout << char(27) << "[1m" << "                           USER'S TURN                                 " << char(27) << "[0m" << endl;

      printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards),userScore,dealerScore,userfinished); //Prints table for user visual appeal

      cout << char(27) << "[1m" << "You have blackjack! You win automatically!" << char(27) << "[0m" << endl;

      didYouWin = true;
      blackjack = true;

      wallet+=2.5*currentBet; //blackjack reward bonus

      cout << endl << char(27) << "[1m" << "Your turn is over." << endl << endl << "Enter any key to continue: " << char(27) << "[0m" << endl;

      string anyKey;
      cin >> anyKey;
    }

    else {

      // -------USER MOVE -----------------------
      bool continueUserTurn = true;
      bool doubleCheck = false;

      cout << char(27) << "[1m" << "                           USER'S TURN                                 " << char(27) << "[0m" << endl;

      printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards),userScore,dealerScore,userfinished);

      while (continueUserTurn){ // user turn continues until function returns false
        continueUserTurn = user(playerCards,deck,topCardIndex,userScore, currentBet, wallet, doubleCheck);

        system("clear");

        cout << char(27) << "[1m" << "                           USER'S TURN                                 " << char(27) << "[0m" << endl;

        printBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards),userScore,dealerScore,userfinished);

        if (doubleCheck) cout << endl << char(27) << "[1m" << "Due to insufficient funds, you can not double your bet. Hence your move counts as a Hit" << char(27) << "[0m" << endl << endl;
        doubleCheck = false;
      }

      cout << endl << char(27) << "[1m" << "Your turn is over." << endl << endl << "Enter any key to continue to Dealer's turn: " << char(27) << "[0m" << endl;

      userfinished = true;

      string anyKey;
      cin >> anyKey;

      // -------DEALER MOVE -----------------------
      dealer(dealerCards, deck, topCardIndex, dealerScore, userScore, wallet,currentBet, playerCards, userfinished);
    }

    // ------- Check winner -----------------------
    winner(userScore, dealerScore, wallet, currentBet, blackjack);

    currentBet = 0;
    cout << endl << char(27) << "[1m" << "Wallet balance: " << wallet << char(27) << "[0m" << endl;

    // ------- Update database -----------------------
    arrayofPlayers[currentplayer].wallet = wallet;
    arrayofPlayers_size = save_file(filename, arrayofPlayers, arrayofPlayers_size);

    // -------Wallet balance check -----------------------

    if(wallet <= 0){
      cout << "You have no more money left, you lose." << endl;
      mainGameLoop = false;
    }

    // -------Play again check -----------------------
    else{
      while(true){
        cout << "Do you want to continue playing? Input Y or N" << endl; // Round playing

        char continueGame;
        cin >> continueGame;

        if(continueGame=='N'){
          mainGameLoop=false;
          break;
        }

        else if (continueGame == 'Y'){
          break;
        }

        else {
          cout << "Invalid Input." << endl;
        }
      }

    }
  }

  // ------- Provide user's with key (given they have money to play again)-----------------------
  if(wallet!=0){
    cout << arrayofPlayers[currentplayer].key << " is your key" << endl;
  }

  return 0;
}
