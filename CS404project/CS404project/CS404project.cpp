// CS404project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int distanceCalc(int dist[][3], int x, int y);

int outputRequestResult(int req[][5]);

int main() {

	ifstream	inputFile;	// define input file stream object


	int emergencyVehicles[10][4];
	int request[7][5];
	int distance[6][3];
	int min;

	inputFile.open("EMV.txt");		// create EMV table
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
	inputFile.close();
	for (i = 0; i < 10; i++) { // set all EMV to available
		emergencyVehicles[i][3] = 1;
	}
	
	inputFile.open("request.txt");		// create request table
	if (!inputFile)
	{
		cout << endl << "Error opening input file." << endl << endl;
		system("pause");
		return -2;
	}
	i = 0;
	inputFile >> request[i][0];
	while (!inputFile.eof() && i < 7)
	{
		inputFile >> request[i][1] >> request[i][2];	// read rest of record fields
		i++;
		inputFile >> request[i][0];

	}
	inputFile.close();
	

	inputFile.open("distance.txt");		// create distance table
	if (!inputFile)
	{
		cout << endl << "Error opening input file." << endl << endl;
		system("pause");
		return -3;
	}
	i = 0;
	inputFile >> distance[i][0];
	while (!inputFile.eof() && i < 6)
	{
		inputFile >> distance[i][1] >> distance[i][2];	// read rest of record fields
		i++;
		inputFile >> distance[i][0];

	}
	inputFile.close();

	for (i = 0; i < 7; i++) {
		min = 100;
		int save = -1;
		for (int j = 0; j < 10; j++) {
			if (emergencyVehicles[j][3] == 1 && emergencyVehicles[j][1] == request[i][1]) {
				int dist = distanceCalc(distance, emergencyVehicles[j][2], request[i][2]); // calculate distance
				if (dist == 0) { // if best case, select EMV and break inner loop
					request[i][3] = emergencyVehicles[j][0];
					request[i][4] = 0;
					emergencyVehicles[j][3] = 0;
					break;
				} else if (dist < min){
					min = dist;
					request[i][3] = emergencyVehicles[j][0];
					request[i][4] = dist;
					save = j; // hold place in case of no better match
					
				}
			}
		}
		emergencyVehicles[save][3] = 0;

	}


	outputRequestResult(request);

	cout << endl << endl;
	system("pause");
	return 0;
}

int distanceCalc(int dist[][3], int x, int y) {
	
	if (x == y) {
		return 0;
	}
	
	else {
		int length = 6;
		for (int i = 0; i < length; i++) {
			if ((x == dist[i][0] || x == dist[i][1]) && (y == dist[i][0] || y == dist[i][1])) {
				return dist[i][2];
			}
		}
	}
	return -1;
}

int outputRequestResult(int req[][5]) {
	int length = 7;
	if (length == 0) { return -1; }

	cout << setw(5) << "ID:" << setw(14) << "VehicleType:" << setw(10)<< "Zipcode:" << setw(12) << "VehicleID:" << setw(11) << "Distance:" << endl;
	for (int i = 0; i < length; i++ ) {
		cout << setw(3) << req[i][0] << setw(14) << req[i][1] << setw(10) << req[i][2] << setw(12) 
			<< req[i][3] << setw(11) << req[i][4] << endl;
	}
	return 0;
}
