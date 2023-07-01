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

void enterGrades(string names[], int grades[][MAX_GRADES], int numStudents, const int MAX_GRADES)
{
    for (int i = 0; i < MAX_GRADES; i++) {
        cout << "Enter grades for Exam " << (i + 1) << endl;
        for (int j = 0; j < numStudents; j++) {
            cout << "Enter grades for " << names[j] << endl;
            cin >> grades[i][j];
        }
    }
}

bool readfromFile(ifstream& fileName, string names[])
{
    bool success;
    success = true;

    {
        bool success;
        success = true;

        for (int i = 0; i < MAX_STUDENTS; i++)
        {

            if (!(fileName >> names[i])) {
                success = false; // evaluate sucess to false if the arrays are not populated
                break;
            }

        }

        return success;
    }
}

//void calculateAverages(string names[], int scores[][MAX_GRADES], int SCORES, int averageScores[])
//{
//
 //   int row;
   // int col;
    //int sum;

    //for (row = 0; row < MAX_STUDENTS; row++)
    //{
     //   sum = 0;
     //   for (col = 0; col < MAX_GRADES; col++)
     //   {
      //      sum = sum + scores[row][col];

        //}
        //averageScores[row] = sum / MAX_GRADES;

    //}
//}

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
    //Variable Declaration 
    char commandEnterGrades = 'e';
    char commandCalculateAverage = 'c';
    char commandGenerateReport = 'r';
    char commandSaveToFile = 's';
    char commandMenu = 'm';
    char commandExit = 'x';
    char userOption;
    int grades[MAX_STUDENTS][MAX_GRADES]; // declares the 2d array 
    int numStudents; // stores grades entered in the varibale

    bool status;

    string names[MAX_STUDENTS]; // array to store names

    ifstream myFile("Student Names.txt"); // open file 


    // Call Functions Welcome and Menu
    welcome();
    menu();




    status = readfromFile(myFile, names);

    userOption = 't';

    while (userOption != commandExit)
    {

        cout << "Please enter an operation to perform:";
        cin >> userOption;

        if (userOption == commandEnterGrades) //call GetCountofTeam function
        {
            ;
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
