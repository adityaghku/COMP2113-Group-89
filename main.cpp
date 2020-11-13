#include <iostream>
#include <string>
using namespace std;

struct playerData{
  string name;
  int purse;
  string key;

  int wins;
  int gamesPlayed; //Stats
  int winPercentage;
};

int main(){

  bool istrue=true,didyouwin=false;
  int purse,currentbet,cardnumber=0;

  playerData P = { };

  str playerCards[15],dealerCards[15],deck[52];

  cout << "Load game or New?" << endl; //Load Game or New Game

  cout << "What is your name?" << endl;
  cin >> name; //Initialise the Cash, name, and key

  generateKey(&key) //Make key only alphabets for simplicity

  cout << "How much money do you want to buy-in?" << endl;
  cin >> purse;

  playerData playerdata[i] = {name, purse, key};

  cout << "Do you want to view the instructions? Y or N" << endl; //Instructions
  char instructions;
  cin >> instructions;
  if(instructions==Y){
    displayInstructions()
  }

  cout << "Begin game" << endl;
  createDeck(&deck); //Adds cards to array in sequential order

  while(istrue){
    cout << "How much do you want to bet (in an increment of 10)" << endl; //bet amount
    cin >> currentbet;
    purse-=currentbet; //for user board display

    shuffleDeck(&deck); //shuffles the deck
    dealCards(deck,&playerCards,&dealerCards,&cardnumber); //Deals the cards to the player and the dealer

    PrintBoard(purse,currentbet,playerCards,dealerCards); //Prints table for user visual appeal

    if blackjack(playerCards){ //checking if the player has blackjack
      purse+=2.5*currentbet;
      cout << "You have blackjack" << endl;
      PrintBoard(purse,currentbet,playerCards,dealerCards);
      didyouwin=true;
    }
    else{

      bool yourTurn=true,dealerTurn=true;
      while(yourTurn){
        cout << "What move will you make? H, S or D." << endl; //Players turn
        char move;
        cin >> move;

        User(&playerCards,deck,&cardnumber,move,&yourTurn); //Has moves and Printboard inside it, updates yourTurn on every move
      }

      while(dealerTurn){
        Dealer(&dealerCards,deck,&cardnumber,&dealerTurn); //Dealers Turn has PrintBoard inside it
      }
    }

    if(YouWon(playerCards,dealerCards)){ //Determine winner of game
      didyouwin=true;
    }

    if(didyouwin){ //Update bet amount of the player
      purse+=2*currentbet
      cout << "You win" << endl;
      PrintBoard(purse,currentbet,playerCards,dealerCards);
    }

    else{
      cout << "You lose" << endl;
      PrintBoard(purse,currentbet,playerCards,dealerCards);
    }

    updateUsers(playerdata.); //update users.txt

    if(purse==0){
      cout << "You have no more money left, you lose" << endl; //Money check condition
      istrue=false;
    }

    cout << "Do you want to continue playing? Input Y or N" << endl; // Round playing
    char continue;
    cin >> continue;
    if(continue=='N'){
      istrue=false;
    }
  }

  if(purse!=0){
    cout << playerdata.key << " is the key";
  }

  return 0;
}
