#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_GRADES = 2;

void welcome()
{
    int rowOfPeriods2 = 45;
    string welcome = " Classroom Grades Program ";
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

void enterGrades(int& i, string names[], int grades[][MAX_GRADES], const int MAX_STUDENTS, const int MAX_GRADES)
{
    char userOption = 'y';
    int examNumber = 1;

    while (i < MAX_GRADES && userOption != 'n')
    {
        cout << "Enter grades for Exam " << (i + 1) << endl;
        

        for (int j = 0; j < MAX_STUDENTS; j++)
        {
            cout << "Enter grades for " << names[j] << ": ";
            cin >> grades[i][j];
            cout << endl;
        }
        i++;
        if (i != MAX_GRADES) 
        {
            cout << "Would you like to enter the grades for exam " << (i) << "? ('y'= yes and 'n' = no): ";
            cin >> userOption;
        }
        else if (i == MAX_GRADES) {
            cout << "You've entered all of the exam grades for this semester. Time to calculate averages, final grades, and generate a report!" << endl;
        }
    

    }
} //

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

void calculateAverages(int averageStudentScores[], string letterGrades[], string names[], int grades[][MAX_GRADES], const int MAX_STUDENTS, const int MAX_GRADES)
{

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        double sum = 0;
        for (int j = 0; j < MAX_GRADES; j++) {
            sum += grades[j][i];
        }
        averageStudentScores[i] = sum / MAX_GRADES;

        // Determine letter grade
        if (averageStudentScores[i] >= 95) {
            letterGrades[i] = "A";
        }
        else if (averageStudentScores[i] >= 90 && averageStudentScores[i] < 95) {
            letterGrades[i] = "A-" ;
        }
        else if (averageStudentScores[i] >= 85 && averageStudentScores[i] < 90) {
            letterGrades[i] = "B";
        }
        else if (averageStudentScores[i] >= 80 && averageStudentScores[i] < 85) {
            letterGrades[i] = "B-";
        }
        else if (averageStudentScores[i] >= 75 && averageStudentScores[i] < 80) {
            letterGrades[i] = "C";
        }
        else if (averageStudentScores[i] >= 70 && averageStudentScores[i] < 75) {
            letterGrades[i] = "C-";
        }
        else if (averageStudentScores[i] >= 65 && averageStudentScores[i] < 70) {
            letterGrades[i] = "D";
        }
        else if (averageStudentScores[i] >= 60 && averageStudentScores[i] < 65) {
            letterGrades[i] = "D-";
        }
        else {
            letterGrades[i] = "F";
        }
    }

    // Display the calculated averages and letter grades
    cout << endl << "Calculated averages and letter grades:" << endl;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << names[i] << " - Average: " << averageStudentScores[i] << ", Grade: " << letterGrades[i] << endl;
    }
}

void generateReport(int averageStudentScores[], string letterGrades[], string names[], int grades[][MAX_GRADES], const int MAX_GRADES, const int MAX_STUDENTS) //Ask for help
{
    int periodsOne = 15;
    int periodsTwo = 10;
    int PeriodsThree = 8;
    int averageColumn = 1;

    ofstream outFile;

    cout << setfill('.');

    outFile.open("Student Report.txt");

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        cout << left << setw(periodsOne) << names[i];
        outFile << left << setw(periodsOne) << names[i];

        for (int j = 0; j < MAX_GRADES; j++)
        {
            cout << right << setw(periodsTwo) << grades[j][i];
            outFile << right << setw(periodsTwo) << grades[j][i];

        }
        for (int x = 0; x < averageColumn; x++) // Debug
        {
        
            cout << right << setw(periodsTwo) << grades[i];
            outFile << right << setw(periodsTwo) << grades[i];

        }
        for (int y = 0; y < averageColumn; y++) // Debug
        {

            cout << right << setw(periodsTwo) << grades[i];
            outFile << right << setw(periodsTwo) << grades[i];

        }

        cout << endl;
        outFile << endl;
    }

     
    outFile.close();
}

void saveToFile(string names[], int grades[][MAX_GRADES])
{
    ofstream myFile("Student Names.txt");
    if (myFile.is_open()) {
        for (int i = 0; i < MAX_STUDENTS; i++) {
            myFile << "Student Name: " << names[i] << endl;
            myFile << "Grades: ";
            for (int j = 0; j < MAX_GRADES; j++) {
                myFile << grades[i][j] << " ";
            }
            myFile << endl;
            //myFile << "Average Grade: " << averageStudentScores[i] << endl;
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


    int grades[MAX_STUDENTS][MAX_GRADES];
    string names[MAX_STUDENTS];
    int averageStudentScores[MAX_STUDENTS];
    string letterGrades[MAX_STUDENTS];

    int examNumber = 0;
    bool status;


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
             enterGrades(examNumber, names, grades, MAX_STUDENTS, MAX_GRADES);
             
        }
        else if (userOption == commandCalculateAverage) //call GetMostWinningTeam function
        {
            calculateAverages(averageStudentScores, letterGrades, names, grades, MAX_STUDENTS, MAX_GRADES);
        }
        else if (userOption == commandGenerateReport) // call GetTeamForDate function 
        {
            generateReport(averageStudentScores, letterGrades, names, grades, MAX_GRADES, MAX_STUDENTS);
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
