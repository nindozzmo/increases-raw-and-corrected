#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	cout << "Code by Nindozzmo, 2021\n" << endl;
	cout << "This app reads data from file 'input.txt' and counts how many measurments are larger than the previous one. On the output you have 2 results: raw and corrected with three-measurement sliding window. File 'input.txt' must be in a same folder as this app.\n" << endl;

	system("pause");

	ifstream datafile; //initializing imput stream and opening ext file	
	datafile.open ("input.txt");

	datafile.is_open() ? cout << "\nFile is sucsessfully opened!\n" << endl : cout << "\nERROR! FILE 'INPUT.TXT' IS MISSING OR CORRUPTED.\n" << endl; //checking success
	
	system("pause");

	vector <int> datavector; //initializing vector

	int data = 0;

	while (datafile >> data) //reading data from file to vector
	{
		datavector.push_back(data);
	}

	datafile.close(); //closing external file

	int rawinc = 0, corrinc = 0;

	for (int i = 0; i < datavector.size() - 1; i++) //comparison raw
	{
		int a = datavector[i];
		int b = datavector[i + 1];

		if (a < b) rawinc++;
	}

	for (int i = 0; i < datavector.size() - 3; i++) //comparison corrected
	{
		int a = datavector[i] + datavector[i + 1] + datavector[i + 2];
		int b = datavector[i + 1] + datavector[i + 2] + datavector[i + 3];

		if (a < b) corrinc++;
	}
	
	cout << "The total number of increases is:\n" << endl;
	cout << "raw - " << rawinc << "; " << "corrected - " << corrinc << "\n" << endl;

	system("pause > 0");
	return 0;
}