#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include "DisplacementCalculator.h"

void IDisplacement()
{

    string Measurement_System;
    string Measurement_Type;

    string InvalidResponse = " is an invalid response, Please try again. Please make sure to use either a 1 or a 2. Please try again.";

    double pi = 3.14159;
    double Bore;
    double Stroke;
    double Cylinder_Count;

    char BoreConfirmation;
    char StrokeConfirmation;
    char Cylinder_CountConfirmation;

    std::cout << "Displacement Calculator 2022" << std::endl;
    std::cout << "Please select the Measurement System of choice using the chart below." << std::endl;
    std::cout << "1: Imperial System" << std::endl
              << "2: Metric System" << std::endl;
    std::cout << "User Answer: ";
    std::cin >> Measurement_System;

    while ((Measurement_System != "1") && (Measurement_System != "2"))
    {
        std::cout << Measurement_System << InvalidResponse << std::endl;
        cout << "User Answer: ";
        cin >> Measurement_System;
    }

    if (Measurement_System == "1")
    {
        Measurement_Type = "Inches";
    }

    if (Measurement_System == "2")
    {
        Measurement_Type = "Millimeters";
    }

    std::cout << "Please input your Bore in " << Measurement_Type << "." << endl;
    std::cout << "User Answer: ";
    std::cin >> Bore;
    std::cout << "Your bore is: " << Bore << ", Correct? [Y/N]" << endl;
    std::cout << "User Answer: ";
    std::cin >> BoreConfirmation;

    while ((BoreConfirmation != 'y') && (BoreConfirmation != 'n'))
    {
        std::cout << BoreConfirmation << InvalidResponse << std::endl;
        std::cout << "User Answer: ";
        std::cin >> BoreConfirmation;
    }

    while (BoreConfirmation == 'n')
    {
        std::cout << "Please enter a new Bore." << std::endl;
        std::cout << "User Answer: ";
        std::cin >> Bore;
        std::cout << "Your bore is: " << Bore << ", Correct? [Y/N]" << std::endl;
        std::cin >> BoreConfirmation;
    }

    while ((BoreConfirmation != 'y') && (BoreConfirmation != 'n'))
    {
        std::cout << BoreConfirmation << InvalidResponse << std::endl;
        std::cout << "User Answer: ";
        std::cin >> BoreConfirmation;
    }

    if (BoreConfirmation == 'y')
    {
        std::cout << "Please input your Stroke " << Measurement_Type << "." << std::endl;
        std::cout << "User Answer: ";
        std::cin >> Stroke;
        std::cout << "Your Stroke is: " << Stroke << ", Correct? [Y/N]" << std::endl;
        std::cout << "User Answer: ";
        std::cin >> StrokeConfirmation;
    }

    while (StrokeConfirmation == 'n')
    {
        std::cout << "Please enter a new Stroke." << std::endl;
        std::cout << "User Answer: ";
        std::cin >> Stroke;
        std::cout << "Your bore is: " << Stroke << ", Correct? [Y/N]" << std::endl;
        std::cin >> StrokeConfirmation;
    }

    if (StrokeConfirmation == 'y')
    {
        std::cout << "Please input your Cylinder Count." << std::endl;
        std::cout << "User Answer: ";
        std::cin >> Cylinder_Count;
        std::cout << "Your Cylinder Count is: " << Cylinder_Count << ", Correct? [Y/N]" << std::endl;
        std::cout << "User Answer: ";
        std::cin >> Cylinder_CountConfirmation;
    }

    while (Cylinder_CountConfirmation == 'n')
    {
        std::cout << "Please enter a new Cylinder Count." << std::endl;
        std::cout << "User Answer: ";
        std::cin >> Cylinder_Count;
        std::cout << "Your bore is: " << Cylinder_Count << ", Correct? [Y/N]" << std::endl;
        std::cin >> Cylinder_CountConfirmation;
    }

    string ResultFilePrompt;

    if ((Cylinder_CountConfirmation == 'y') && (Measurement_System == "1"))
    {
        double CI_Displacement = ((pi * Bore / 2 * Bore / 2) * Stroke) * Cylinder_Count; // Maths
        double Liters_Displacement = (CI_Displacement / 61.024); // Maths

        std::cout << CI_Displacement << "; Cubic Inch(es)" << std::endl; // Output of Displacement in Cubic Inch(es)
        std::cout << Liters_Displacement << "; Liter(s)" << std::endl;   // Output of Displacement in Liter(s)

        std::cout << "Would you like to save your results on the desktop? [Y/N]" << std::endl;
        std::cout << "User Answer:";
        std::cin >> ResultFilePrompt;
    }

    if ((Cylinder_CountConfirmation == 'y') && (Measurement_System == "2"))
    {

        double CC_Displacement = ((0.7854 * Bore * Bore) * Stroke * Cylinder_Count) / 1000; // Maths

        std::cout << CC_Displacement << "; Cubic Centimeter(s)" << std::endl; // Output of Displacement in Cubic Centimeter(s)

        std::cout << "Would you like to save your results on the desktop? [Y/N]" << std::endl;
        std::cout << "User Answer:";
        std::cin >> ResultFilePrompt;
    };

    string Result;
    if ((Measurement_System == "1") && (ResultFilePrompt == "y")) // Printing Imperial System File results.
    {
        double CI_Displacement = ((pi * Bore / 2 * Bore / 2) * Stroke) * Cylinder_Count;
        double Liters_Displacement = (CI_Displacement / 61.024);
        string CIs = to_string(CI_Displacement);
        string LD = to_string(Liters_Displacement);
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[100];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 100, "(Imperial System) Catalyst 360 Displacemetn Calculator results on: %c", timeinfo);
        std::cout << buffer;
        std::fstream resultfile;
        resultfile.open("C:\\Users\\Hot Dog\\Desktop\\Results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        if (resultfile.is_open())
        {
            resultfile << buffer;
            resultfile << std::endl;
            resultfile << "Bore: ";
            resultfile << Bore;
            resultfile << std::endl;
            resultfile << "Stroke: ";
            resultfile << Stroke;
            resultfile << std::endl;
            resultfile << "Cubic Inches: ";
            resultfile << CIs;
            resultfile << std::endl;
            resultfile << "Liters Displacement: ";
            resultfile << LD;
            resultfile << std::endl;
            resultfile << std::endl; // Extra line break to leave gap for Future Results.
            resultfile.close();
            std::cout << "Created a text file on the desktop with your results.";
        }
        else
        {
            std::cout << "Error Opening/Closing and or printing to file. Please try again later.";
        }
    }

    if ((Measurement_System == "2") && (ResultFilePrompt == "y")) // Printing Metric System File results.
    {
        double CC_Displacement = ((0.7854 * Bore * Bore) * Stroke * Cylinder_Count) / 1000; // Maths
        string CCs = to_string(CC_Displacement);
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[100];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 100, "(Metric System) Catalyst 360 Displacemetn Calculator results on: %c", timeinfo);
        std::cout << buffer;
        std::fstream resultfile;
        resultfile.open("C:\\Users\\Hot Dog\\Desktop\\Results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        if (resultfile.is_open())
        {
            resultfile << buffer;
            resultfile << std::endl;
            resultfile << "Bore: ";
            resultfile << Bore;
            resultfile << std::endl;
            resultfile << "Stroke: ";
            resultfile << Stroke;
            resultfile << std::endl;
            resultfile << "Cubic Inches: ";
            resultfile << CCs;
            resultfile << std::endl;
            resultfile << std::endl; // Extra line break to leave gap for Future Results.
            resultfile.close();
            std::cout << "Created a text file on the desktop with your results.";
        }
        else
        {
            std::cout << "Error Opening/Closing and or printing to file. Please try again later.";
        }
    }

    if ((Measurement_System == "1") && (ResultFilePrompt == "n"))
    {
        std::cout << "No result file created. Press any key to continue... " << std::endl;
        system("pause");
    }

    if ((Measurement_System == "2") && (ResultFilePrompt == "n"))
    {
        std::cout << "No result file created. Press any key to continue... " << std::endl;
        system("pause");
    }

    std::cout << Result << std::endl;
    std::cout << std::endl
              << "Executed all code and exited with code 0" << std::endl;
}