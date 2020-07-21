// CS404project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream	inputFile;	// define input file stream object


	int emergencyVehicles[10][3];

	inputFile.open("EMV.txt");		// open input file object
	if (!inputFile)
	{
		cout << endl << "Error opening input file." << endl << endl;
		system("pause");
		return -1;
	}

	int i = 0;

	inputFile >> emergencyVehicles[i][0];
	while (!inputFile.eof() && i < 10)
	{
		inputFile >> emergencyVehicles[i][1] >> emergencyVehicles[i][2];	// read rest of record fields
		i++;
		inputFile >> emergencyVehicles[i][0];

	}


	cout << endl << endl;
	system("pause");
	return 0;
}
