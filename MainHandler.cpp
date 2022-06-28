// MainHandler.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "CompressionCalculator.h"
#include "DisplacementCalculator.h"

using namespace std;

int main()
{

	system("Color 04");

	string UserInput1;

	cout << "Welcome to Catalyst 360! This program has various engineering tools built into it." << endl << "To select the one you are here to use, Please check the chart below. " << endl;
	cout << "Please type the corresponding name for the program you would like to use." << endl;
	cout << "1: Displacement Calculator (Imperial System and Metric System Supported)" << endl << "2: Compression Ratio Calculator (Imperial System and Metric System Supported)" << endl;
	cout << "User Answer: ";
	cin >> UserInput1;

	while ((UserInput1 != "1") && (UserInput1 != "2")) {
		cout << UserInput1 << " is an invalid response, Please try again." << endl;
		cout << "User Answer: ";
		cin >> UserInput1;
	}

	if (UserInput1 == "1") {
		IDisplacement();
		return 0;
	};

	if (UserInput1 == "2") {
		ICompression();
		return 0;
	};

	return EXIT_SUCCESS;

}
