#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;



int main(int argc, char* argv[]) {


    int ROWS;
    int COLS;

    // Check if the file path is provided as a command line argument
    if (argc < 2) {
        cout << "Please provide the file path as a command line argument." << endl;
        return 1;
    }

    // Open the file
    ifstream file(argv[1]);
    ofstream out(argv[2]);


    file >> ROWS >> COLS;
    ROWS += 1;
    COLS += 2;

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    // Create a 2D array

    // string array[ROWS][COLS];

    string **array = new string *[ROWS];
    for(int i = 0; i<ROWS; i++){
        array[i] = new string[COLS];
    }


    // Read the file line by line
    string line;
    int row = 0;
    while (getline(file, line) && row < ROWS) {
        istringstream iss(line);

        // Read the elements and store them in the array
        for (int col = 0; col < COLS && iss.good(); col++) {
            iss >> array[row][col];
        }

        row++;
    }

    // Close the file
    file.close();

    // return the Student Scores / array
    out << "Student Scores:";
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if(row != 0){
            out << array[row][col] << " ";
            }
        }
        out << endl;
    }
    out << endl;
//     // //creating two arrays. int and string.;

    string **sArray = new string *[ROWS - 1];
    for(int i = 0; i<ROWS; i++){
        array[i] = new string[2];
    }

    string **tArray = new string *[ROWS - 1];
    for(int i = 0; i<ROWS; i++){
        array[i] = new string[COLS - 2];
    }

    for(int i = 0; i < ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            if((i > 0) && (j > 1)){
                tArray[i][j] = array[i][j];
            }
            else if((i > 0) && (j < 2)){
                sArray[i][j] = array[i][j];
                //out << sArray[i][j] << endl;
            }
        }
    }

        out << fixed << setprecision(1); //****************** NEEDS TO BE FIXED!!!!! NOT ROUNDING PROPPERLY

        out << "Exam Averages:" << endl;

        int x;
        double counter;
        double lady;


        int **testArray = new int *[ROWS - 1];
        for(int i = 0; i<ROWS; i++){
            testArray[i] = new int[COLS - 2];
        }

        for(int i = 1; i < ROWS; ++i){
            counter = 0;
            for(int j = 2; j < COLS; ++j){
                x = stoi(tArray[i][j]);
                testArray[i][j] = x;
                counter += testArray[i][j];
            }
            lady = counter / (COLS - 2);
            out << "Exam " << i << " Average: " << lady << endl;
        }
        out << endl;
    
// // //student exam grades

    out << "Student Exam Grades:" << endl;

     for(int i = 1; i < ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            if((i > 0) && (j < 2)){
                out << array[i][j] << " ";
            }
            else
                {
                if(90 <= testArray[i][j]){
                    out << tArray[i][j] << "(A)" << " ";
                }
                else if(80 <= testArray[i][j] && testArray[i][j] < 90){
                    out << tArray[i][j] << "(B)" << " ";
                }
                else
                    {
                    if(70 <= testArray[i][j] && testArray[i][j] < 80){
                    out << tArray[i][j] << "(C)" << " ";
                    }
                    else if(60 <= testArray[i][j] && testArray[i][j]< 70){
                        out << tArray[i][j] << "(D)" << " ";
                    }
                    else
                        {
                            out << testArray[i+1][j] << "(E)" << " ";
                        };
                    };
                }
            }
        out << endl;
    };
out << endl;

// // //exam grades

    out << "Exam Grades:" << endl;
    int examCount = 1;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;


    for(int i = 2; i < (COLS - 2); ++i){
        A = 0;
        B = 0;
        C = 0;
        D = 0;
        E = 0;
        for(int j = 1; j < ROWS; ++j){
            if(i < 2){
            }
            else
                {
                if(90 <= testArray[i][j]){
                    A++;
                }
                else if(80 <= testArray[i][j] && testArray[i][j] < 90){
                    B++;
                }
                else
                    {
                    if(70 <= testArray[i][j] && testArray[i][j] < 80){
                    C++;
                            }
                    else if(60 <= testArray[i][j] && testArray[i][j]< 70){
                        D++;
                            }
                    else
                        {
                            E++;
                        };
                    };
                }
            }
            out << "Exam" << " " << examCount <<  " " << A << "(A)" <<  " " << B << "(B)" << " " << C << "(C)" << " " << D << "(D)" << " " <<E << "(E)" << endl;
        examCount++;
    };
    out << endl;






// //student final grades

    out << "Student Final Grade:" << endl;
    int count = 0;
    double totalPoints = 0;
    double finalTotalPoints = 0;
    int finalCount = 0;

    for(int i = 1; i < (ROWS - 1); ++i){
        totalPoints = 0;
        count = 0;
        for(int j = 0; j < (COLS - 2); ++j){
            if(j < 2){
            }
            else{
                totalPoints += testArray[i][j];
                count++;
            }
        }
        finalTotalPoints += totalPoints;
        finalCount += count;
        out << array[i][0] << " " << array[i][1] << " " << (totalPoints / count);
            if(90 <= (totalPoints / count)){
                    out << "(A)" << " ";
                }
                else if(80 <= (totalPoints / count) && (totalPoints / count) < 90){
                    out << "(B)" << " ";
                }
                else
                    {
                    if(70 <= (totalPoints / count) && (totalPoints / count) < 80){
                    out << "(C)" << " ";
                    }
                    else if(60 <= (totalPoints / count) && (totalPoints / count)< 70){
                        out << "(D)" << " ";
                    }
                    else
                        {
                           out << "(E)" << " ";
                        };
                    }
        out << endl;
    }
    out << endl;

    out << " Class Average Results: " << finalTotalPoints / finalCount;


    return 0;
};