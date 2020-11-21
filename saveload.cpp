#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include "saveload.h"
using namespace std;

//Save and load the data, outputs it to a file called users.txt

string filename = "users.txt";

/*
Purpose: Random key generator
Inputs:
  - None
Outputs:
  - A string of alphabets
*/
string generateKey(){
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    string random_string;

    for (size_t i = 0; i < 6; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

/*
Purpose: reads data from users.txt and stores it in a class
Inputs:
  - pointer to array of type playerData, and the size of the aray
Outputs:
  - returns the  total number of players
*/

int load_data(playerData * &arrayofPlayers, int &arrayofPlayers_size){
  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail())
  {
      cout << "Error in file opening." << endl;
      return 0;
  }

  int i = 0;
  string line;
  while (getline(fin, line)){
    if (i >= arrayofPlayers_size - 1){
      grow_file(arrayofPlayers, arrayofPlayers_size);
    }

    if (i < arrayofPlayers_size) {
          istringstream iss(line);
          if (!getline(iss, arrayofPlayers[i].name,','))
              break;
          string temp;
          if (getline(iss, temp,','))

              arrayofPlayers[i].wallet = stoi(temp);

          if (!getline(iss, arrayofPlayers[i].key))
              break;
          ++i;
    }
  }

  fin.close();
  return i;
}

/*
Purpose: Dynamically increase the array size if needed
Inputs:
  - Pointer to array and the size of the array
Outputs:
  - No return value, amends the size of the array dynamically
*/

void grow_file(playerData * &arrayofPlayers, int &arrayofPlayers_size){

	playerData *pd_new = new playerData[arrayofPlayers_size + 3];

	for (int i = 0; i < arrayofPlayers_size; i++)
	{
		pd_new[i] = arrayofPlayers[i];
	}

	delete [] arrayofPlayers;

	arrayofPlayers = pd_new;

	arrayofPlayers_size += 3;
}

/*
Purpose: Adds a new user
Inputs: pointer to array, number of players and the size of the array
Outputs: Adds data to the array of the new user
*/

void addUser(playerData * &arrayofPlayers, int &numberofPlayers, int arrayofPlayers_size){

  if (numberofPlayers >= arrayofPlayers_size - 1) {
    grow_file(arrayofPlayers, arrayofPlayers_size);
  }

	char ans;
	string str;

	getline(cin, str); // flush the keyboard buffer
	cout << "Please enter a name: ";
	getline(cin, arrayofPlayers[numberofPlayers].name);

  while(true){
    cout << "How much money do you want to buy-in?" << endl;
    int temp;

    cin >> temp;

    arrayofPlayers[numberofPlayers].wallet = temp;

    if (arrayofPlayers[numberofPlayers].wallet <=0){
      cout << "Invalid Input. Please Try again." << endl;
    }
    else{
      break;
    }
  }


  string key;
  key = generateKey();
  arrayofPlayers[numberofPlayers].key = key;
	cout << "Your key is: " << key << endl;
  cout << "Enter any key to continue to your turn: " << endl;
  string anyKey;
  cin >> anyKey;

	numberofPlayers++;
}

/*
Purpose: Saves data to users.txt
Inputs: filename, the array and the number of players
Outputs: returns the number of players and updates data to users.txt
*/

int save_file(string filename, playerData arrayofPlayers[], int numberofPlayers)
{
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i;
    for (i = 0; i < numberofPlayers; i++)
    {
        fout << arrayofPlayers[i].name << "," << arrayofPlayers[i].wallet << "," << arrayofPlayers[i].key << endl;
    }

    fout.close();
    return i;
}
