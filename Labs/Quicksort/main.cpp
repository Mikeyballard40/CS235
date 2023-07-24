#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "QS.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
#define CONSOLE 0

using namespace std;

QS<int> qs;

int main(int argc, char* argv[]){

  

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
        
        if(item1 == "QuickSort") {
            int item2;
            iss >> item2;

            qs.Quicksort(item2);
            out << item2 << " OK";
        }
        else if (item1 == "Capacity"){
            out << qs.capacity();
        }
        else if(item1 == "Clear"){
            qs.clear();
            out << "OK";
        }
        else if(item1 == "AddToArray"){
            int item2;
            bool firstElement = true;
            out << " ";
            while (iss >> item2) {
                if (!firstElement) {
                    out << ",";
                } else {
                    firstElement = false;
                }
                qs.addElement(item2);
                out << item2;
            }
            out << " OK";
        }
        else if(item1 == "Size"){
            out << qs.size();
            
        }
        else if(item1 == "PrintArray"){
            out << qs.toString();
        }
        else if(item1 == "MedianOfThree"){
            int item2, item3, med;
            iss >> item2 >> item3;
            med = qs.medianOfThree(item2, item3);
            out << item2 << "," << item3 << " = " << med;
        }
        else if(item1 == "Partition"){
            int left, right, piv, end;
            iss >> left >> right >> piv;
            end = qs.partition(left, right, piv);
            out << left << "," << right << "," << piv << " = " << end;
        }
        else if(item1 == "SortAll"){
            if(qs.sortAll()) {
                qs.sortAll();
                out << "OK";
            }
            else out << "Error";
        }
        else if(item1 == "Sort"){
            int item2, item3;
            iss >> item2 >> item3;
            if(qs.sort(item2, item3)) {
                qs.sort(item2, item3);
                out << item2 << "," << item3 << " OK";
            }
            else out << "Error";
        }
        else if(item1 == "Stats"){
            int item2, item3;
            out << qs.stat() << endl;
        }

        out << endl;
    }

qs.clear();

out.clear();
in.clear();
cout.clear();
if (!CONSOLE) {
    delete &out;
}
}