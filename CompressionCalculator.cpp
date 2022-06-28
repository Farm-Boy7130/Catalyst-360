#include "CompressionCalculator.h"

using namespace std;

void ICompression() {

	double Bore;
	double Stroke;

	int UserInput1;
	string MeasurementSystem;
	string MeasurementSystemMeasurement;

	cout << "Compression Ratio v1.0.0 | Please enter your Measurement System of choice:" << endl << "1: Imperial System " << endl << "2: Metric System " << endl;
	cin >> UserInput1;

	if (UserInput1 == 1) {
		MeasurementSystem = "Imperial";
		MeasurementSystemMeasurement = "Inches";
	} 
	if (UserInput1 == 2) {
		MeasurementSystem = "Metric";
		MeasurementSystemMeasurement = "Centimeters";
	}

	cout << "Please input your Bore in " << MeasurementSystemMeasurement << endl;
	cin >> Bore;

}