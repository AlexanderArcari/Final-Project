// Final-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void welcome()
{
    
    int rowOfPeriods2 = 45;
    string welcome = "Classroom Grades Program";
    int rowOfPeriods1 = 90 + welcome.length();

    cout << setfill('-');
    cout << setw(rowOfPeriods1) << "" << endl;
    cout << setw(rowOfPeriods2 +welcome.length()) << welcome << setw(rowOfPeriods2) << "" << endl;
    cout << setw(rowOfPeriods1) << "" << endl << endl;

}
void menu() 
{
    char commandEnterGrades = 'e';
    char commandCalculateAverage = 'c';
    char commandGenerateReport = 'r';
    char commandSaveToFile = 's';
    char commandMenu = 'm';
    char commandExit = 'x';

    cout << endl << endl;

    cout << "Enter '" << commandEnterGrades << "' to enter grades." << endl;
    cout << "Enter '" << commandCalculateAverage << "' to calculate averages." << endl;
    cout << "Enter '" << commandGenerateReport << "' to generate a grade report for the class." << endl;
    cout << "Enter '" << commandSaveToFile << "' to save work to file." << endl;
    cout << "Enter '" << commandMenu << "' to call the menu options." << endl;
    cout << "Enter '" << commandExit << "' to exit the program." << endl << endl << endl;

}

void enterGrades() 
{

}


void calculateAverages() 
{ //this can also be an int

}

bool readfromFile() 
{

    return true;
}

void generateReport()
{

}

void saveToFile()
{

}


int main()
{
    //Variable Declaration 
    char commandEnterGrades = 'e';
    char commandCalculateAverage = 'c';
    char commandGenerateReport = 'r';
    char commandSaveToFile = 's';
    char commandMenu = 'm';
    char commandExit = 'x';
    char userOption;


    // Call Functions Welcome and Menu
    welcome();
    menu();


    userOption = 't';

    while (userOption != commandExit)
    {

        cout << "Please enter an operation to perform:";
        cin >> userOption;

        if (userOption == commandGetCount) //call GetCountofTeam function
        {
            //GetCountOfTeam();
        }
        else if (userOption == commandGetMostWinning) //call GetMostWinningTeam function
        {
            //GetMostWinningTeam();
        }
        else if (userOption == commandGetTeamDate) // call GetTeamForDate function 
        {
            //GetTeamForDate();
        }
        else if (userOption == commandConvertCase) // call ConvertTeamNameCase function
        {
            cout << "Please enter the case to change ('u' = upper and 'l' = lower):";
            cin >> userOption;

            if (userOption == upperChoice) { //changes the value of to_upper depending on the customers option
                to_upper = true;
            }
            else if (userOption == lowerChoice)
            {
                to_upper = false;
            }

            ConvertTeamNameCase(to_upper, teamNames, SIZE_DATA);
        }

        else if (customerOption == commandExit) {
            cout << "Good Bye." << endl;
        }
    }

    // Return 0 to indicate success.
    return 0;

}


