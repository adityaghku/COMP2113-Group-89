//printDealerCards.cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Purpose: Prints out the dealers cards only
Inputs:
  - x: takes length of dealer cards and the cards, as well as a check in case the user
  has finished playing
Outputs:
  - y: prints the dealers card on the UI interface. If the user has not finished, does not
  reveal all cards to the user
*/
void printDealerCards(int n, string dealerCards[15], bool userfinished){
  int l = 34 - 7*(n-1);

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << " ---- " << " ";
    }
    else{
      cout << " ---- " << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){ //10 requires an additional character
        cout << "|" << setw(30) << "|";
        if(userfinished || i==0 ){ //hide one card
          cout << dealerCards[i] << " |" << " ";
        }
        else{
          cout << "    |" << " ";
        }
      }
      else{
        cout << "|" << setw(30) << "|";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "  |" << " ";
        }
        else{
          cout << "    |" << " ";
        }
      }
    }
    else{
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){
        cout << "|";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << " |" << " ";
        }
        else{
          cout << "    |" << " ";
        }

      }
      else{
        cout << "|";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "  |" << " ";
        }
        else{
          cout << "    |" << " ";
        }
      }
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << "|    |" << " ";
    }
    else{
      cout << "|    |" << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){
        cout << "|" << setw(30) << "|" << " ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "   |" << " ";
        }
      }
      else{
        cout << "|" << setw(30) << "|" << "  ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "   |" << " ";
        }

      }
    }
    else{
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){
        cout << "|" << " ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "   |" << " ";
        }
      }
      else{
        cout << "|" << "  ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "  |" << " ";
        }

      }
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << " ---- " << " ";
    }
    else{
      cout << " ---- " << " ";
    }
  }
  cout << setw(l) << "|" << endl;
}
