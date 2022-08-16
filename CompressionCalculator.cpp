#include "CompressionCalculator.h"

void ICompression()
{

	string InvalidResponse = " is an invalid response, Please try again. Please make sure to use either a 1 or a 2. Please try again.";

	double Bore;
	double Stroke;

	int UserInput1;
	string UserInput2;
	string MeasurementSystem;
	string MeasurementSystemMeasurement;

	std::cout << "Compression Ratio 2022 | Please enter your Measurement System of choice:" << std::endl
			  << "1: Imperial System " << std::endl
			  << "2: Metric System " << std::endl;
	std::cin >> UserInput1;

	if (UserInput1 == 1)
	{
		MeasurementSystem = "Imperial";
		MeasurementSystemMeasurement = "Inches";
	}
	if (UserInput1 == 2)
	{
		MeasurementSystem = "Metric";
		MeasurementSystemMeasurement = "Centimeters";
	}

	std::cout << "Please specify which program you want to use following the chart below: " << std::endl;
	std::cout << "1: Regular Compression Ratio Calculator" << std::endl;
	std::cout << "2: Reverse Compression Ratio Calculator" << std::endl;
	std::cout << "User Answer: ";
	std::cin >> UserInput2;

	while ((UserInput2 != "1") && (UserInput2 != "2"))
	{
		std::cout << "You entered: '" << UserInput2 << "' This is an invalid Option. Please try again.";
		std::cin >> UserInput2;
	}

	if (UserInput2 == "1")
	{
		std::cout << "Please input your Bore in " << MeasurementSystemMeasurement << std::endl;
		std::cin >> Bore;
	}

	if (UserInput2 == "2")
	{
		string tagType = "Alpha";
		double CompressionRatioDesired;

		if (tagType == "Alpha")
		{
			string UserAcknowledged;

			std::cout << "This portion of the program is in Alpha development/Testing. Please Acknowledge this. [Y/N]";
			std::cin >> UserAcknowledged;
			if (UserAcknowledged == "n")
			{
				std::cout << "Okay. Ending program in 3 seconds.";
				exit(0);
			}
		}

		std::cout << "Please enter the desired Compression Ratio." << std::endl;
		std::cout << "User Answer: ";
		std::cin >> CompressionRatioDesired;
		std::cout << "Your desired Compression Ratio is: " << CompressionRatioDesired << ", Correct? [Y/N]" << std::endl;
		std::cout << "User Answer: ";
	}

	std::cout << std::endl
			  << "Executed all code and exited with Code 0." << std::endl;
	system("pause");
}