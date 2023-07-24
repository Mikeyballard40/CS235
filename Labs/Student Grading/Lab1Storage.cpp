#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>
#include <vector>


using namespace std;

void removeDupWord(string str, string array[])
{
    string word;
    int count = 0;
    istringstream iss(str);
    while (getline(iss, word, ' ')) {
        array[count] = word;
        count++;
    };
 
};

int main(int argc, char* argv[]) { //student scores

ifstream in(argv[1]);
ofstream out(argv[2]);

    int StudentNo;
    int TestNo;
    in >> StudentNo >> TestNo;
    int testscore;

    out << "Student Scores:" << endl;

    string row1;
    getline(in, row1);
    out << row1 << endl;
    string row2;
    getline(in, row2);
    out << row2 << endl;
    string row3;
    getline(in, row3);
    out << row3 << endl;
    string row4;
    getline(in, row4);
    out << row4 << endl;
    string row5;
    getline(in, row5);
    out << row5 << endl;
    string row6;
    getline(in, row6);
    out << row6 << endl;
    string row7;
    getline(in, row7);
    out << row7 << endl;
    string row8;
    getline(in, row8);
    out << row8 << endl;

    string a(row1);
    string b(row2);
    string c(row3);
    string d(row4);
    string e(row5);
    string f(row6);
    string g(row7);

    string array1[] = {};
    string array2[] = {};
    string array3[] = {};
    string array4[] = {};
    string array5[] = {};
    string array6[] = {};
    string array7[] = {};

 

   // string array[] = {row1, row2, row3, row4, row5, row6, row7};
    string array[] = {a, b, c, d, e, f, g};

    removeDupWord(row2, array2);

    for(int i; i < (TestNo + 2); ++i){
        cout << array2[i] << endl;
    }
        


    //THIS WORKS FOR THE FIRST ELEMENT OF THE FIRST ARRAY
        // string n;
        // istringstream word(b);
        // word >> n;
        // cout << n << "\n";
    

        //-----------------------------------------------//


// //Student Scores

//     cout << "Student Scores:" << endl;

//     for(int i = 0; i < StudentNo; ++i){
//         for(int j = 0; j < TestNo; ++j){
//             cout << argv[i][j] << " ";
//         }
//         cout << endl;

//     }

//  //exam averages

//     cout << "Exam Averages:" << endl;

//     int exams[] = {};
//     int indexCount = 0;
//     int finalCount = 1;

//     for(int i = 0; i < StudentNo; ++i)
//         {indexCount = 0;
//         for(int j = 1; j < (TestNo); ++j){
//             exams[indexCount] += argv[i][j];
//             indexCount++;
//         }
//         }
//     for(int i = 0; i < sizeof(indexCount); ++i)
//         cout << "Exam" << finalCount << "Average = " << (exams[finalCount - 1] / indexCount) << endl;


// //student exam grades

//     cout << "Student Exam Grades:" << endl;

//     for(int i = 0; i < StudentNo; ++i){
//         for(int j = 0; j < TestNo; ++j){
//             if(90 <= j){
//                 cout << argv[i][j] << "(A)" << " ";
//             }
//             else if(80 <= j < 90){
//                 cout << argv[i][j] << "(B)" << " ";
//             }
//             else if(70 <= j < 80){
//                 cout << argv[i][j] << "(C)" << " ";
//             }
//             else if(60 <= j < 70){
//                 cout << argv[i][j] << "(D)" << " ";
//             }
//             else{
//                 cout << argv[i][j] << "(E)" << " ";
//             };
//         }
//         cout << endl;
//     }


// //exam grades

//     cout << "Exam Grades:" << endl;
//     int examCount = 1;
//     int A = 0;
//     int B = 0;
//     int C = 0;
//     int D = 0;
//     int E = 0;

//     for(int i = 0; i < StudentNo; ++i){
//         A = 0;
//         B = 0;
//         C = 0;
//         D = 0;
//         E = 0;
//         for(int j = 0; j < TestNo; ++j){
//             if(90 <= j){
//                 A++;
//             }
//             else if(80 <= j < 90){
//                 B++;
//             }
//             else if(70 <= j < 80){
//                 C++;
//             }
//             else if(60 <= j < 70){
//                 D++;
//             }
//             else{
//                 E++;
//             }
//         }
//         cout << "Exam" << examCount << A << "(A)" << B << "(B)" << C << "(C)" << D << "(D)" << E << "(E)" << endl;
//         examCount++;
//     }

// //student final grades

//     cout << "Student Final Grade:" << endl;
//     int count = 0;
//     int totalPoints = 0;
//     int finalTotalPoints = 0;
//     int finalCount = 0;

//     for(int i = 0; i < StudentNo; ++i){
//         totalPoints = 0;
//         count = 0;
//         for(int j = 0; j < TestNo; ++j){
//             if(count = 0){
//                 cout << j;
//                 count++;
//             }
//             else{
//                 totalPoints += j;
//                 count++;
//             }
//         }
//     }
//         totalPoints = totalPoints / (count - 1);
//         finalTotalPoints += totalPoints;
//         finalCount += count;

//         if(90 <= totalPoints){
//                 cout << "(A)";
//             }
//             else if(80 <= totalPoints < 90){
//                 cout << "(B)";
//             }
//             else if(70 <= totalPoints < 80){
//                 cout << "(C)";
//             }
//             else if(60 <= totalPoints < 70){
//                 cout << "(D)";
//             }
//             else{
//                 cout << "(E)";
//             }


    return 0;
};