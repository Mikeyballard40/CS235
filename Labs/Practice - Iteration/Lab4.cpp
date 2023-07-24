#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LinkedList.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
#define CONSOLE 0

using namespace std;


int main(int argc, char* argv[])
{

ifstream in(argv[1]);
ostream& out = CONSOLE ? cout : *(new ofstream(argv[2]));

LinkedList<string> list;

int count = 0;
int copyCount = 0;

for (string line; getline(in, line);)
{
   string item1, item2;
   if (line.size() == 0) continue;
   istringstream iss(line);
   iss >> item1;
   out << item1 << " "; // command OR element#0
   if (item1 == "Insert")
   {
    count++;
        while (iss >> item2) // words in the string
        {
            list.push_front(item2);
            out << item2 << " ";
        }     
        out << endl;
   }

    // FUNTIONS 
   if (item1 == "Clear"){
    list.clear();
    out << "OK" << endl;
    count = 0;
   }

    if (item1 == "PrintList"){
        out << list.toString();
        out << endl;
    }

    //out << endl;



    if (item1 == "Size"){
        out << list.size();
    }

    if (item1 == "Empty"){
        if(list.empty()==1){
            out << "true";
        } else{
            out << "false";
        }
    }

    if (item1 == "First"){
        if (count < 1){
            out << "Empty!";
        } else{
            out << list.front();
        }
   }

    if (item1 == "Delete"){
        list.pop_front();
        if (list.toString() == "Empty!"){
            out << "Empty!";
        } else{
            out << "OK";
        }
    }

    if (item1 == "Remove"){
        iss >> item2;
        out << item2;
        list.remove(item2);
    }

    if (item1 == "Reverse"){
        if(count < 1){
            out << "Empty!";
        } else{
        list.reverse();
        out << "OK";
        }
    }

    if (item1 == "Copy"){
        if(list.toString() == "Empty!"){
            copyCount = 0;
            out << "OK";
        }else if(list.toString() != list.toStringC()){
            list.Copy();
            copyCount++;
            out << "OK";
        }else{
            out << "Empty!";
        }
    }

    if (item1 == "PrintCopy"){
        if(copyCount < 1){
            out << "Empty!";
        } else{ // Create a deep copy of the original list
            out << list.toStringC(); 
        }
    }

    if (item1 == "Iterate"){
        LinkedList<string>::Iterator iter = list.begin();
        if (list.empty()==1){
            out << "Empty!" << endl;
        } else{
        while (iter != list.end())
        {
        out << endl << " [" << *iter << "]";
        ++iter;
        }
        out << endl;
        }   
    }

    // MUST IMPLEMENT FIND

    if (item1 == "InsertAfter"){
        LinkedList<string>::Iterator iter = list.begin();
        string replacement;
        string insertAfter;
        iss >> replacement >> insertAfter;
        list.insert_after(insertAfter, replacement);
        LinkedList<string>::Iterator boolea = list.find(insertAfter);
        if (boolea != list.end()){
            out << replacement << " " << insertAfter << " " << "OK" << endl;
        } else{
            out << replacement << " " << insertAfter << " " << "Not Found" << endl;
        }
    }

    if (item1 == "InsertBefore"){
        LinkedList<string>::Iterator iter = list.begin();
        string replacement;
        string insertBefore;
        iss >> replacement >> insertBefore;
        list.insert(insertBefore, replacement);
        LinkedList<string>::Iterator boolea = list.find(insertBefore);
        if (boolea != list.end()){
            out << replacement << " " << insertBefore << " " << "OK" << endl;
        } else{
            out << replacement << " " << insertBefore << " " << "Not Found" << endl;
        }
    }    

    if (item1 == "Find"){
        LinkedList<string>::Iterator iter = list.begin();
        string value;
        iss >> value;
        LinkedList<string>::Iterator boolea = list.find(value);
        if (boolea != list.end()){
            out << value << " " << "OK" << endl;
        } else {
            out << value << " " << "Not Found" << endl;
        }
    }

    if (item1 == "Erase"){
        LinkedList<string>::Iterator iter = list.begin();
        string value;
        iss >> value;
        LinkedList<string>::Iterator boolea = list.find(value);
        if (boolea != list.end()){
            list.erase(value);
            out << value << " " << "OK" << endl;
        } else {
            out << value << " " << "Not Found" << endl;
        }
    }

    if (item1 == "Replace"){
        LinkedList<string>::Iterator iter = list.begin();
        string oldV;
        string newV;
        iss >> oldV >> newV;
        list.replace(oldV, newV);
        LinkedList<string>::Iterator boolea = list.find(newV);
        if (boolea != list.end()){
            out << oldV << " " << newV << " " << "OK" << endl;
        } else{
            out << oldV << " " << newV << " " << "Not Found" << endl;
        }
    }

}

list.clear();
out.clear();
in.clear();
cout.clear();
if (!CONSOLE) {
    delete &out;
}

}


