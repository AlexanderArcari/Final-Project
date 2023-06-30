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
    cout << setw(rowOfPeriods2 + welcome.length()) << welcome << setw(rowOfPeriods2) << "" << endl;
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

void enterGrades(int grades[][MAX_GRADES], int numStudents)
{
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter grades for student " << (i + 1) << ": ";
        for (int j = 0; j < MAX_GRADES; j++) {
            cin >> grades[i][j];
        }
    }
}

void calculateAverages()
{
    // Implement the logic to calculate averages here
}

void readFromFile()
{
    ifstream myFile;
    myFile.open("Student Names.txt");
    if (myFile.is_open()) {
        char mystring;
        while (myFile) {
            mystring = myFile.get();
            cout << mystring;
        }
        myFile.close();
    }
    else {
        cerr << "Error opening file." << endl;
    }
}

void generateReport(string names[], int scores[][MAX_GRADES], int averageStudentScores[])
{
    int periodsOne = 15;
    int periodsTwo = 10;
    int PeriodsThree = 8;

    ofstream outFile;
    outFile.open("scores.dat");

    cout << setfill('.');

    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << left << setw(periodsOne) << names[i];
        outFile << left << setw(periodsOne) << names[i];

        for (int j = 0; j < MAX_GRADES; j++) {
            cout << right << setw(periodsTwo) << scores[i][j];
            outFile << right << setw(periodsTwo) << scores[i][j];
        }

        cout << right << setw(PeriodsThree) << averageStudentScores[i] << " ";
        outFile << right << setw(PeriodsThree) << averageStudentScores[i] << " ";

        cout << endl;
        outFile << endl;
    }

    outFile.close();
}

void saveToFile(string names[], int scores[][MAX_GRADES], int averageStudentScores[])
{
    ofstream myFile("Student Names.txt");
    if (myFile.is_open()) {
        for (int i = 0; i < MAX_STUDENTS; i++) {
            myFile << "Student Name: " << names[i] << endl;
            myFile << "Grades: ";
            for (int j = 0; j < MAX_GRADES; j++) {
                myFile << scores[i][j] << " ";
            }
            myFile << endl;
            myFile << "Average Grade: " << averageStudentScores[i] << endl;
            myFile << endl;
        }
        myFile.close();
    }
    else {
        cerr << "Error opening file." << endl;
    }
}

int main()
{
    char commandEnterGrades = 'e';
    char commandCalculateAverage = 'c';
    char commandGenerateReport = 'r';
    char commandSaveToFile = 's';
    char commandMenu = 'm';
    char commandExit = 'x';
    char userOption;
    int grades[MAX_STUDENTS][MAX_GRADES];
    int numStudents;

    welcome();
    menu();

    userOption = 't';

    while (userOption != commandExit)
    {
        cout << "Please enter an operation to perform:";
        cin >> userOption;

        if (userOption == commandEnterGrades)
        {
            cout << "Enter the number of students: ";
            cin >> numStudents;

            enterGrades(grades, numStudents);

            // Display the entered grades
            cout << "Entered grades:" << endl;
            for (int i = 0; i < numStudents; i++) {
                cout << "Student " << (i + 1) << ": ";
                for (int j = 0; j < MAX_GRADES; j++) {
                    cout << grades[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (userOption == commandCalculateAverage)
        {
            calculateAverages();
        }
        else if (userOption == commandGenerateReport)
        {
            // Implement the logic to generate the report here
        }
        else if (userOption == commandSaveToFile)
        {
            // Implement the logic to save to file here
        }
        else if (userOption == commandMenu)
        {
            menu();
        }
        else if (userOption == commandExit)
        {
            cout << "Goodbye." << endl;
        }
    }

    return 0;
}
