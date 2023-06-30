// Final-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_GRADES = 5;

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

void readfromFile() {


    std::ifstream myFile; myFile.open("Student Names.txt");
    if (myFile.is_open()){

    char mystring;
    while (myFile) {
        mystring = myFile.get();
        std::cout << mystring;

       
    }
    return;
}
}

void generateReport(string names[], int scores[][MAX_GRADES], int MAX_GRADES, int averageStudentScores[])
{
    int periodsOne = 15;
    int periodsTwo = 10;
    int PeriodsThree = 8;

    ofstream outFile;

    cout << setfill('.');

    outFile.open("scores.dat");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << left << setw(periodsOne) << names[i];
        outFile << left << setw(periodsOne) << names[i];

        for (int j = 0; j < MAX_GRADES; j++) {
            cout << right << setw(periodsTwo) << scores[i][j];
            outFile << right << setw(periodsTwo) << scores[i][j];

        }
        for (int x = 0; x < 1; x++) {
            cout << right << setw(PeriodsThree) << averageStudentScores[i] << " ";
            outFile << right << setw(PeriodsThree) << averageStudentScores[i] << " ";
        }
        cout << endl;
        outFile << endl;
    }
    outFile.close();
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

        if (userOption == commandEnterGrades) //call GetCountofTeam function
        {
            //GetCountOfTeam();
        }
        else if (userOption == commandCalculateAverage) //call GetMostWinningTeam function
        {
            //GetMostWinningTeam();
        }
        else if (userOption == commandGenerateReport) // call GetTeamForDate function 
        {
            //GetTeamForDate();
        }
        else if (userOption == commandSaveToFile) // call ConvertTeamNameCase function
        {
            //saveToFile()

        }
        else if (userOption == commandMenu) {
            menu();
        } 
        else if (userOption == commandExit) {
            cout << "Good Bye." << endl;
        }
    }

    // Return 0 to indicate success.
    return 0;

}


