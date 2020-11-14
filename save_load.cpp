#include <iostream>
#include <fstream>
using namespace std;

string filename = "users.txt";

int load_data(playerData * &pd, int &pd_size){
  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail())
  {
      cout << "Error in file opening." << endl;
      return 0;
  }

  int i = 0;
  string line;
  while (getline(fin, line))
  {
  if (i >= pd_size)
    grow_file(pd, pd_size, 2);

  // extract a name and a phone no. from a line
  if (i < pd_size) {
        istringstream iss(line);
        if (!getline(iss, pd[i].name,','))
            break;
        if (!getline(iss, pd[i].phone_no))
            break;
        ++i;
    }

  }

  fin.close();
  return i;
}


void loadGame(string inputkey){

}

void updateUsers(playerData pd[]){
  ofstream fout;
  fout.open(filename.c_str());
  if (fout.fail())
  {
      cout << "Error in file opening." << endl;
      return 0;
  }

  fout << pd[i].name << "," << pb[i].phone_no << endl;

  fout.close();
  return i;
}

void grow_file(playerData * &pd, int &pd_size, int n)
{
	// create a new dynamic array with a new size = max_size + n
	playerData * pd_new = new playerData[pd_size + n];

	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < pd_size; i++)
	{
		pd_new[i] = pd[i];
	}

	// destroy the old dynamic array to free up the memory allocated to it
	delete [] pd;
	// assign the pointer to the new dynamic array to the pointer variable
	pd = pd_new;
	// update the size of the array
	pd_size += n;

	return;
}

int addUser(playerData pd[], int nRec)
{
	char ans;
	string str;

	getline(cin, str); // flush the keyboard buffer
	cout << "Please enter a name: ";
	getline(cin, pd[nRec].name);
	cout << "Please enter a phone number: ";
	getline(cin, pd[nRec].phone_no);
	cout << endl;
	cout << "Name:\t" << pd[nRec].name << endl;
    cout << "Phone#:\t" << pd[nRec].phone_no << endl << endl;
    cout << "Add to phonebook (y/n)? ";
	cin >> ans;
	if (ans == 'y')
	{
		cout << "1 record added." << endl;
		nRec++;
	}

	return nRec;
}
