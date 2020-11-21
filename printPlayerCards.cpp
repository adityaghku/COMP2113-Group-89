//printPlayerCards.cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Purpose: Prints out the players cards
Inputs:
  - x: takes length of player cards and the cards
Outputs:
  - y: prints the dealers card on the UI interface
*/
void printPlayerCards(int n, string playerCards[15]){
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
      temp = playerCards[i][0];
      if (temp == '1'){
        cout << "|" << setw(30) << "|" << playerCards[i] << " |" << " ";
      }
      else{
        cout << "|" << setw(30) << "|" << playerCards[i] << "  |" << " ";
      }
    }
    else{
      char temp;
      temp = playerCards[i][0];
      if (temp == '1'){
        cout << "|" << playerCards[i] << " |" << " ";
      }
      else{
        cout << "|" << playerCards[i] << "  |" << " ";
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
      temp = playerCards[i][0];
      if (temp=='1'){
        cout << "|" << setw(30) << "|" << " " << playerCards[i] << "|" << " ";
      }
      else{
        cout << "|" << setw(30) << "|" << "  " << playerCards[i] << "|" << " ";
      }
    }
    else{
      char temp;
      temp = playerCards[i][0];
      if (temp=='1'){
        cout << "|" << " " << playerCards[i] << "|" << " ";
      }
      else{
        cout << "|" << "  " << playerCards[i] << "|" << " ";
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
