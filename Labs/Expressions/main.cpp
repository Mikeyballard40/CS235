#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "ExpressionManager.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
#define CONSOLE 0

using namespace std;

int main(int argc, char* argv[]){

    ExpressionManager expression;


    ifstream in(argv[1]);
    ostream& out = CONSOLE ? cout : *(new ofstream(argv[2]));

    if (!in) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string item1;
        iss >> item1;
        out << item1 << " ";

        if(item1 == "Expression:"){
            int count = 0;
            
            string item2;
            while(iss >> item2){
                cout << item2 << endl;
                expression.push_back(item2);
                count++;
            }
            
            out << expression.toString();
        }

        if(item1 == "Infix:"){
            out << expression.infix();
        }
        else if(item1 == "Prefix:"){
            out << expression.infix();
        }
        else if(item1 == "Postfix:"){
            out << expression.infix();
        }
        else if(item1 == "Value:"){
            out << expression.infix();
        }




        out << endl;


    }
}