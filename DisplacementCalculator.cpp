#include "DisplacementCalculator.h"

void IDisplacement()
{

    string Measurement_System;

    double pi = 3.14159;
    double Bore;
    double Stroke;
    int Cylinder_Count;

    char BoreConfirmation;
    char StrokeConfirmation;
    char Cylinder_CountConfirmation;

    cout << "Displacement Calculator 2022" << endl;
	cout << "Please select the Measurement System of choice using the chart below." << endl;
	cout << "1: Imperial System" << endl << "2: Metric System" << endl;
	cout << "User Answer: ";
	cin >> Measurement_System;

    while ((Measurement_System != "1") && (Measurement_System != "Imperial System") && (Measurement_System != "Imperial") && (Measurement_System != "2") && (Measurement_System != "Metric System") && (Measurement_System != "Metric")) {
		cout << Measurement_System << " is an invalid response, Please try again." << endl;
		cout << "User Answer: ";
		cin >> Measurement_System;
	}

    cout << "Please input your Bore." << endl;
    cout << "User Answer: ";
    cin >> Bore;
    cout << "Your bore is: " << Bore << ", Correct? [Y/N]" << endl;
    cout << "User Answer: ";
    cin >> BoreConfirmation;

    while (BoreConfirmation == 'n') {
        cout << "Please enter a new Bore." << endl;
        cout << "User Answer: ";
        cin >> Bore;
        cout << "Your bore is: " << Bore << ", Correct? [Y/N]" << endl;
        cin >> BoreConfirmation;
    }

    cout << "Please input your Stroke." << endl;
    cout << "User Answer: ";
    cin >> Stroke;
    cout << "Your Stroke is: " << Stroke << ", Correct? [Y/N]" << endl;
    cout << "User Answer: ";
    cin >> StrokeConfirmation;

    while (StrokeConfirmation == 'n') {
        cout << "Please enter a new Stroke." << endl;
        cout << "User Answer: ";
        cin >> Stroke;
        cout << "Your bore is: " << Stroke << ", Correct? [Y/N]" << endl;
        cin >> StrokeConfirmation;
    }

    cout << "Please input your Cylinder Count." << endl;
    cout << "User Answer: ";
    cin >> Cylinder_Count;
    cout << "Your Cylinder Count is: " << Cylinder_Count << ", Correct? [Y/N]" << endl;
    cout << "User Answer: ";
    cin >> Cylinder_CountConfirmation;

    while (Cylinder_CountConfirmation == 'n') {
        cout << "Please enter a new Cylinder Count." << endl;
        cout << "User Answer: ";
        cin >> Cylinder_Count;
        cout << "Your bore is: " << Cylinder_Count << ", Correct? [Y/N]" << endl;
        cin >> Cylinder_CountConfirmation;
    }

    	double CI_Displacement = pi * Bore / 2 * Bore / 2 * Stroke * Cylinder_Count; // Maths
		double Liters_Displacement = CI_Displacement / 61.024; // Maths

		cout << CI_Displacement << "; Cubic Inch(es)" << endl; // Output of Displacement in Cubic Inch(es)
		cout << Liters_Displacement << "; Liter(s)" << endl; // Output of Displacement in Liter(s)

    system("pause");

}