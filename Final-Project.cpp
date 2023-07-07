#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_GRADES = 4;

struct StudentGradeInfo { // utilizes a structure to create multiple members for the total number of students.
                          // Written by: Alexander Arcari
    string name = "John";
    int examGrade1 =0;
    int examGrade2 = 0;
    int examGrade3 = 0;
    int examGrade4 = 0;
    int averageGrade = 0;
    string letterGrade = "A";
};

void welcome() // This function creates a title for our program to make it appear more professional
               // Written by: Arber Prendi
{
    int rowOfPeriods2 = 45;
    string welcome = " Classroom Grades Program ";
    int rowOfPeriods1 = 90 + welcome.length();

    cout << setfill('-');
    cout << setw(rowOfPeriods1-1) << "" << endl;
    cout << setw(rowOfPeriods2 + welcome.length()) << welcome << setw(rowOfPeriods2 -1) << "" << endl;
    cout << setw(rowOfPeriods1-1) << "" << endl << endl;
}

void menu() // This function displays the users options and can be called at any point in the program
            // Written by: Alexander Arcari 
            
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

void enterGrades(int& i, string names[], int grades[][MAX_GRADES], const int MAX_STUDENTS, const int MAX_GRADES) // This function uses arrays, loops, and decision structures to allow user to input grades for exams 
                                                                                                                 // It passes the i value in as reference so that the user can enter and leave the function at any point and keep the progress made
                                                                                                                 // Written by Anthony Al-Khafaji w/ some debugging by Alex 
{
    char userOption = 'y';
    
    int rowOfPeriods1 = 90;


    while (i < MAX_GRADES && userOption != 'n')
    {

        cout << setfill('-');
        cout << setw(rowOfPeriods1 -1) << "" << endl;
        cout << right << setw(44) << " Exam " << (i + 1) << " Grades " << setw(37) << " " << endl;
        cout << setw(rowOfPeriods1 - 1) << "";
        cout << endl << endl;
        
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
            cout << endl;
        }
        else if (i == MAX_GRADES) {
            cout << "You've entered all of the exam grades for this semester. Time to calculate averages, final grades, and generate a report!" << endl;
        }
    
    }
} 

void editStudentGrade(string names[], int grades[][MAX_GRADES], const int MAX_STUDENTS, const int MAX_GRADES) {
    string studentName;
    int examNumber;
    int newGrade;

    cout << "Enter the name of the student whose grade you would like to change: " << endl;
    cin >> studentName;

    //Find name in array

    int namesIndex = -1;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (names[i] == studentName) {
            namesIndex = i;
            break;
        }
    }

    if (namesIndex == -1) {
        cout << "Error, student not found in class." << endl;

    }

    cout << "Enter the exam number that you would like to change (1-4): ";
    cin >> examNumber;

    if (examNumber > MAX_GRADES || examNumber < 1) {
        cout << "Invalid exam number." << endl;
    }

    cout << "Enter the new exam score: ";
    cin >> newGrade;



}

bool readfromFile(ifstream& fileName, string names[]) // This function uses arrays, decision structures, and loops to read a file of names into an array. If the file does not populate the array, an error message is displayed. 
                                                        // Written by: Arber Prendi
{
    bool success;
    success = true;

    {
        bool success;
        success = true;

        for (int i = 0; i < MAX_STUDENTS; i++)
        {

            if (!(fileName >> names[i])) {
                success = false; // evaluate success to false if arrays are not populated
                break;
            }

        }

        return success;
    }
}


void calculateAverages(int averageStudentScores[], string letterGrades[], string names[], int grades[][MAX_GRADES], const int MAX_STUDENTS, const int MAX_GRADES) // This function uses a nested loop, multi decision structure,
                                                                                                                                                                  // and a single loop to calculate and display the average, as well as determine the students letter grade
                                                                                                                                                                  // Written by: Anthony Al-Khafaji
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
                                                           // Written by: Alexander Arcari

    cout << "Name: " << student1.name << endl;
    cout << "Exam 1: " << student1.examGrade1 << endl;
    cout << "Exam 2: " << student1.examGrade2 << endl;
    cout << "Exam 3: " << student1.examGrade3 << endl;
    cout << "Exam 4: " << student1.examGrade4 << endl;
    cout << "Average Student Score: " << student1.averageGrade << endl;
    cout << "Final Grade: " << student1.letterGrade << endl;
}

void generateFinalReport(int averageStudentScores[], string letterGrades[], string names[], int grades[][MAX_GRADES], const int MAX_GRADES, const int MAX_STUDENTS) //This function utilizes a nested for loops and arrays to display a final report of grades for all students
                                                                                                                                                                    // Written by: Anthony Al-Khafaji & Alexander Arcari 
{
    int periodsOne = 15;
    int periodsTwo = 10;
    int periodsThree = 8;
    int averageColumn = 1;
    
    cout << setfill(' ');
    cout << left << setw(periodsOne) << "Name";
    cout << right << setw(periodsTwo) << "Exam 1";
    cout << right << setw(periodsTwo) << "Exam 2";
    cout << right << setw(periodsTwo) << "Exam 3";
    cout << right << setw(periodsTwo) << "Exam 4";
    cout << right << setw(periodsThree) << "Average" << endl;
    cout << setfill(' ');

    cout << setw(periodsOne + periodsTwo + periodsTwo + periodsThree) << "" << endl;

    cout << setfill('.');

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        cout << left << setw(periodsOne) << names[i];
        

        for (int j = 0; j < MAX_GRADES; j++)
        {
            cout << right << setw(periodsTwo) << grades[j][i];
           
        }

        cout << right << setw(periodsThree) << averageStudentScores[i];
        

        cout << endl;
        
    }
}


void saveToFile(int averageStudentScores[], string letterGrades[], string names[], int grades[][MAX_GRADES], const int MAX_GRADES, const int MAX_STUDENTS) // Utilizes the ofstream, and nested for loops to save the report to a file.
                                                                                                                                                            // Written by: Arber Prendi
{
    int periodsOne = 15;
    int periodsTwo = 10;
    int periodsThree = 8;
    int averageColumn = 1;

    ofstream outFile;
    outFile.open("Student Final Report.txt");

    outFile << setfill(' ');
    outFile << left << setw(periodsOne) << "Name";
    outFile << right << setw(periodsTwo) << "Exam 1";
    outFile << right << setw(periodsTwo) << "Exam 2";
    outFile << right << setw(periodsTwo) << "Exam 3";
    outFile << right << setw(periodsTwo) << "Exam 4";
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


    ifstream myFile("Student Names.txt"); // Open Student Names file 

    // Call Functions Welcome and Menu
    welcome();
    menu();

    status = readfromFile(myFile, names);

    userOption = 't';

    while (userOption != commandExit)
    {

        cout << "Please enter an menu option: ";
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
                                                                  // Written by Alexander Arcari

            //Structure Variable Declaration
            StudentGradeInfo student1, student2, student3, student4, student5, student6, student7, student8, student9, student10;

            //Student 1
            student1.name = names[0];
            student1.examGrade1 = grades[0][0];
            student1.examGrade2 = grades[1][0];
            student1.examGrade3 = grades[2][0];
            student1.examGrade4 = grades[3][0];
            student1.averageGrade = averageStudentScores[0];
            student1.letterGrade = letterGrades[0];

            //Student 2
            student2.name = names[1];
            student2.examGrade1 = grades[0][1];
            student2.examGrade2 = grades[1][1];
            student2.examGrade3 = grades[2][1];
            student2.examGrade4 = grades[3][1];
            student2.averageGrade = averageStudentScores[1];
            student2.letterGrade = letterGrades[1];

            //Student 3
            student3.name = names[2];
            student3.examGrade1 = grades[0][2];
            student3.examGrade2 = grades[1][2];
            student3.examGrade3 = grades[2][2];
            student3.examGrade4 = grades[3][2];
            student3.averageGrade = averageStudentScores[2];
            student3.letterGrade = letterGrades[2];

            //Student 4
            student4.name = names[3];
            student4.examGrade1 = grades[0][3];
            student4.examGrade2 = grades[1][3];
            student4.examGrade3 = grades[2][3];
            student4.examGrade4 = grades[3][3];
            student4.averageGrade = averageStudentScores[3];
            student4.letterGrade = letterGrades[3];

            //Student 5
            student5.name = names[4];
            student5.examGrade1 = grades[0][4];
            student5.examGrade2 = grades[1][4];
            student5.examGrade3 = grades[2][4];
            student5.examGrade4 = grades[3][4];
            student5.averageGrade = averageStudentScores[4];
            student5.letterGrade = letterGrades[4];
            
            //Student 6
            student6.name = names[5];
            student6.examGrade1 = grades[0][5];
            student6.examGrade2 = grades[1][5];
            student6.examGrade3 = grades[2][5];
            student6.examGrade4 = grades[3][5];
            student6.averageGrade = averageStudentScores[5];
            student6.letterGrade = letterGrades[5];

            //Student 7
            student7.name = names[6];
            student7.examGrade1 = grades[0][6];
            student7.examGrade2 = grades[1][6];
            student7.examGrade3 = grades[2][6];
            student7.examGrade4 = grades[3][6];
            student7.averageGrade = averageStudentScores[6];
            student7.letterGrade = letterGrades[6];

            //Student 8
            student8.name = names[7];
            student8.examGrade1 = grades[0][7];
            student8.examGrade2 = grades[1][7];
            student8.examGrade3 = grades[2][7];
            student8.examGrade4 = grades[3][7];
            student8.averageGrade = averageStudentScores[7];
            student8.letterGrade = letterGrades[7];

            //Student 9
            student9.name = names[8];
            student9.examGrade1 = grades[0][8];
            student9.examGrade2 = grades[1][8];
            student9.examGrade3 = grades[2][8];
            student9.examGrade4 = grades[3][8];
            student9.averageGrade = averageStudentScores[8];
            student9.letterGrade = letterGrades[8];

            //Student 10
            student10.name = names[9];
            student10.examGrade1 = grades[0][9];
            student10.examGrade2 = grades[1][9];
            student10.examGrade3 = grades[2][9];
            student10.examGrade4 = grades[3][9];
            student10.averageGrade = averageStudentScores[9];
            student10.letterGrade = letterGrades[9];


            cout << "For which student would you like to generate a report? ";
            cin >> studentName;
            cout << endl;

            if (studentName == student1.name) { // multi-if structure to determine which student member is sent to the generate individual report function
                generateIndividualReport(student1);
            }
            else if (studentName == student2.name) {
                generateIndividualReport(student2);
            }
            else if (studentName == student3.name) {
                generateIndividualReport(student3);
            }
            else if (studentName == student4.name) {
                generateIndividualReport(student4);
            }
            else if (studentName == student5.name) {
                generateIndividualReport(student5);
            }
            else if (studentName == student6.name) {
                generateIndividualReport(student6);
            }
            else if (studentName == student7.name) {
                generateIndividualReport(student7);
            }
            else if (studentName == student8.name) {
                generateIndividualReport(student8);
            }
            else if (studentName == student9.name) {
                generateIndividualReport(student9);
            }
            else if (studentName == student10.name) {
                generateIndividualReport(student10);
            }
            else {
                cout << "Hmm, try again." << endl;
                break;
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



