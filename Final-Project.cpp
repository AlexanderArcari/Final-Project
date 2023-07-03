#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_GRADES = 2;

struct StudentGradeInfo { // utilizes a structure to create multiple members for x number of students.
    string name;
    int examGrade1;
    int examGrade2;
    //int examGrade3;
    //int examGrade4;
    int averageGrade;
    string letterGrade;
};

void welcome()
{
    int rowOfPeriods2 = 45;
    string welcome = " Classroom Grades Program ";
    int rowOfPeriods1 = 90 + welcome.length();

    cout << setfill('-');
    cout << setw(rowOfPeriods1-1) << "" << endl;
    cout << setw(rowOfPeriods2 + welcome.length()) << welcome << setw(rowOfPeriods2 -1) << "" << endl;
    cout << setw(rowOfPeriods1-1) << "" << endl << endl;
}

void menu()
{
    char commandEnterGrades = 'e';
    char commandCalculateAverage = 'c';
    char commandGenerateReport = 'f';
    char commandGenerateIndividualReport = 'i';
    char commandSaveToFile = 's';
    char commandMenu = 'm';
    char commandExit = 'x';

    cout << endl << endl;

    cout << "Enter '" << commandEnterGrades << "' to enter grades." << endl;
    cout << "Enter '" << commandCalculateAverage << "' to calculate averages." << endl;
    cout << "Enter '" << commandGenerateIndividualReport << "' to generate an individual report." << endl;
    cout << "Enter '" << commandGenerateReport << "' to generate a final grade report for the class." << endl;
    cout << "Enter '" << commandSaveToFile << "' to save work to file." << endl;
    cout << "Enter '" << commandMenu << "' to call the menu options." << endl;
    cout << "Enter '" << commandExit << "' to exit the program." << endl << endl << endl;
}

void enterGrades(int& i, string names[], int grades[][MAX_GRADES], const int MAX_STUDENTS, const int MAX_GRADES)
{
    char userOption = 'y';
    
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
            cout << "Would you like to enter the grades for exam " << (i+1) << "? ('y'= yes and 'n' = no): ";
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
        int sum = 0;
        for (int j =0; j < MAX_GRADES; j++) {
            sum = sum + grades[j][i];
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

void generateIndividualReport(StudentGradeInfo student1) { // This function prints the individual grades, average grade, and letter grade to the screen for a student of the user's choosing. 

    cout << "Name: " << student1.name << endl;
    cout << "Exam 1: " << student1.examGrade1 << endl;
    cout << "Exam 2: " << student1.examGrade2 << endl;
    cout << "Average Student Score: " << student1.averageGrade << endl;
    cout << "Final Grade: " << student1.letterGrade << endl;
}

void generateFinalReport(int averageStudentScores[], string letterGrades[], string names[], int grades[][MAX_GRADES], const int MAX_GRADES, const int MAX_STUDENTS) //Ask for help
{
    int periodsOne = 15;
    int periodsTwo = 10;
    int periodsThree = 8;
    int averageColumn = 1;

    ofstream outFile;
    outFile.open("Student Report.txt");
    
    cout << setfill('.');
    cout << left << setw(periodsOne) << "Name";
    cout << right << setw(periodsTwo) << "Exam 1";
    cout << right << setw(periodsTwo) << "Exam 2";
    cout << right << setw(periodsThree) << "Average" << endl;
    cout << setfill(' ');

    cout << setw(periodsOne + periodsTwo + periodsTwo + periodsThree) << "" << endl;

    cout << setfill('.');

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        cout << left << setw(periodsOne) << names[i];
        outFile << left << setw(periodsOne) << names[i];

        for (int j = 0; j < MAX_GRADES; j++)
        {
            cout << right << setw(periodsTwo) << grades[j][i];
            outFile << right << setw(periodsTwo) << grades[j][i];
        }

        cout << right << setw(periodsThree) << averageStudentScores[i];
        outFile << right << setw(periodsThree) << averageStudentScores[i];

        cout << endl;
        outFile << endl;
    }

     
    outFile.close();
}

void saveToFile(int averageStudentScores[], string letterGrades[], string names[], int grades[][MAX_GRADES], const int MAX_GRADES, const int MAX_STUDENTS)
{
    int periodsOne = 15;
    int periodsTwo = 10;
    int periodsThree = 8;
    int averageColumn = 1;

    ofstream outFile;
    outFile.open("Student Final Report.txt");

    outFile << setfill('.');
    outFile << left << setw(periodsOne) << "Name";
    outFile << right << setw(periodsTwo) << "Exam 1";
    outFile << right << setw(periodsTwo) << "Exam 2";
    outFile << right << setw(periodsThree) << "Average" << endl;
    outFile << setfill(' ');

    outFile << setw(periodsOne + periodsTwo + periodsTwo + periodsThree) << "" << endl;

    outFile << setfill('.');

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        outFile << left << setw(periodsOne) << names[i];

        for (int j = 0; j < MAX_GRADES; j++)
        {
            outFile << right << setw(periodsTwo) << grades[j][i];
        }

        outFile << right << setw(periodsThree) << averageStudentScores[i];

        outFile << endl;
    }


    outFile.close();
    cout << "Your file has been saved as 'Student Final Report.txt'" << endl;
}


int main()
{
    //Variable Declaration & File Opening
    char commandEnterGrades = 'e';
    char commandCalculateAverage = 'c';
    char commandGenerateFinalReport = 'f';
    char commandGenerateIndividualReport = 'i';
    char commandSaveToFile = 's';
    char commandMenu = 'm';
    char commandExit = 'x';
    char userOption;
    string studentName;
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
        cout << endl;

        if (userOption == commandEnterGrades) //call GetCountofTeam function
        {
             enterGrades(examNumber, names, grades, MAX_STUDENTS, MAX_GRADES);
             
        }
        else if (userOption == commandCalculateAverage) //call GetMostWinningTeam function
        {
            calculateAverages(averageStudentScores, letterGrades, names, grades, MAX_STUDENTS, MAX_GRADES);
        }
        else if (userOption == commandGenerateIndividualReport) { // Command Generate Individual Report calls a function that allows the user to enter a name of a student that they want an individual report for. 

            //Structure Variable Declaration
            StudentGradeInfo student1, student2, student3, student4, student5, student6, student7, student8, student9, student10;

            //Student 1
            student1.name = names[0];
            student1.examGrade1 = grades[0][0];
            student1.examGrade2 = grades[1][0];
            //student1.examGrade3 = grades[2][];
            //student1.examGrade4 = grades[3][];
            student1.averageGrade = averageStudentScores[0];
            student1.letterGrade = letterGrades[0];

            //Student 2
            student2.name = names[1];
            student2.examGrade1 = grades[0][1];
            student2.examGrade2 = grades[1][1];
            student2.averageGrade = averageStudentScores[1];
            student2.letterGrade = letterGrades[1];

            cout << "For which student would you like to generate a report? ";
            cin >> studentName;


            if (studentName == student1.name) { // multi-if structure to determine which student member is sent to the generate individual report function
                generateIndividualReport(student1);
            }
            else if (studentName == student2.name) {
                generateIndividualReport(student2);
            }
            else if (studentName == student3.name) {
                
            }
            else if (studentName == student4.name) {
                
            }
            else if (studentName == student5.name) {
               
            }
            else if (studentName == student6.name) {
               
            }
            else if (studentName == student7.name) {
                
            }
            else if (studentName == student8.name) {
                
            }
            else if (studentName == student9.name) {
                
            }
            else if (studentName == student10.name) {
                
            }

        }
        else if (userOption == commandGenerateFinalReport) // call Generate Final Report function 
        {
            generateFinalReport(averageStudentScores, letterGrades, names, grades, MAX_GRADES, MAX_STUDENTS);
        }
        else if (userOption == commandSaveToFile) // call ConvertTeamNameCase function
        {
            saveToFile(averageStudentScores, letterGrades, names, grades, MAX_GRADES, MAX_STUDENTS); // Call Save to File

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



