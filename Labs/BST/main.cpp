#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BST.h"

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

    ifstream in(argv[1]);
    ostream& out = CONSOLE ? cout : *(new ofstream(argv[2]));

    bool In = false;
    bool St = false;

    BST<int> intBST;
    BST<string> stringBST;
    BST<int> cIntBST;
    BST<string> cStringBST;


    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string item1;
        iss >> item1;
        out << item1 << " ";

        if (item1 == "INT") {
            In = true;
            St = false;
            out << " OK";
        }
        else if (item1 == "STRING") {
            In = false;
            St = true;
            out << " OK";
        }
        else if (item1 == "add") {
            if (In) {
                int value;
                iss >> value;
                if(intBST.addNode(value)){
                out << value << " OK";
                intBST.addNode(value);
                } else {
                    out << value << " Error";
                }
            }
            else if (St) {
                string value;
                iss >> value;
                if(stringBST.addNode(value)){
                out << value << " OK";
                stringBST.addNode(value);
                } else {
                    out << value << " Error";
                }
            }
        }
        else if (item1 == "print") {
            if(In == false && St == false) out << " Error";
            else if (In) {
                out << intBST.toString();
            }
            else if (St) {
                out << stringBST.toString();
            }
        }
        else if (item1 == "size"){
            if (In) {
                out << intBST.size();
            }
            else if (St) {
                out << stringBST.size();
            }
        }
        else if (item1 == "clear"){
            if (In) {
                intBST.clearTree();
                out << "OK";
            }
            else if (St) {
                stringBST.clearTree();
                out << "OK";
            }
           
        }
        else if (item1 == "remove"){
            if (In) {
                int item2;
                iss >> item2;
                if(intBST.removeNode(item2)) out << item2 << " OK";
                else out << item2 << " Error";
            }
            else if (St) {
                string item2;
                iss >> item2;
                if(stringBST.removeNode(item2)) out << item2 << " OK";
                else out << item2 << " Error";
            }
        }
        else if (item1 == "find"){
            if (In) {
                int item2;
                iss >> item2;
                if(intBST.find(item2)){
                out << item2 << " found";
                }else{
                out << item2 << " not found";
                }
            }
            else if (St) {
                string item2;
                iss >> item2;
                if(stringBST.find(item2)){
                out << item2 << " found";
                }else{
                out << item2 << " not found";
                }
            }
        }
        else if (item1 == "copy"){
            if(In == false && St == false){
                    out << " Error";
                }
            if (In) {
                intBST.deepCopy();
                out << "OK";
            }
            else if (St) {
                stringBST.deepCopy();
                out << "OK";
            }
        }


        else if (item1 == "printcopy") {
            if (In) {
                out << intBST.toStringC();
            }
            else if (St) {
                out << stringBST.toStringC();

            }
           
        }   
        out << endl;

    }

out.clear();
in.clear();
cout.clear();
if (!CONSOLE) {
    delete &out;
}

return 0;
      

}