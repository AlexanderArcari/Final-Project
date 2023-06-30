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

// grades is left empty to allow the array to have a variable number of rows(students)
// Max grades indicated the number of coloumns (grades)
// numstudents specifies the size of the first array (grades)

void enterGrades(int grades[][MAX_GRADES], int numStudents) 
{
    for (int i = 0; i < numStudents; i++){
        cout << "Enter grades for student " << (i + 1) << ": ";

        for (int j = 0; j < MAX_GRADES; j++){
            cin >> grades[i][j];
        }
    }
}


void calculateAverages(string names[], int scores[][MAX_GRADES], int SCORES, int averageScores[])
{

    int row;
    int col;
    int sum;

    for (row = 0; row < MAX_STUDENTS; row++)
    {
        sum = 0;
        for (col = 0; col < MAX_GRADES; col++)
        {
            sum = sum + scores[row][col];

        }
        averageScores[row] = sum / MAX_GRADES;

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

        for (int i = 0; i < MAX_STUDENTS; i++) {
            cout << names[i] << endl;
        }
        return success;
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

//void saveToFile(string names[], int grades[][MAX_GRADES], int MAX_GRADES, int averageStudentScores[])
//{
  //  ofstream myFile("Student Grade Report.txt");

    //if (!myFile) {
      //  cerr << "Error opening file.\n";
       // return;
    //}

    //myFile << "Student Names:\n" << names[];
    //myFile << "Grade" << grades[i] << endl;
    //myFile << "Average grade" << averageStudentScores[i] << endl;
   

  //  myFile.close();
    
//}



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

// cout << "Enter the number of students: ";
// cin >> numStudents;
// enterGrades(grades, numStudents);

// This function displays entered grades
// cout << "Entered grades: " << endl;
    // for (int i = 0; i < numStudents; i++)
        // cout << "Student " << (i + 1) << ": ";
        // for (int j = 0; j < MAX_GRADES; j++) {
            // cout << grades[i][j] << " ";  
        //} 
        // cout << std::endl;
    //}
