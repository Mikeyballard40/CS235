#include <iostream>
#include <string>
#include <fstream>
#include <vector> //
#include "snap.h"
#include "csg.h"
#include "cdh.h"
#include "cr.h"

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

VS_MEM_CHECK 

ifstream in(argv[1]);
ostream& out = CONSOLE ? cout : *(new ofstream(argv[2]));

vector<snap*> SnapV;
vector<csg*> csgV;
vector<cdh*> cdhV;
vector<cr*> crV;


//declairing variables
string ID;
string name;
string address;
string phone;
string course;
string grade;
string day;
string time;
string room;

out << "Input Strings:" << endl;
//first checkpoint checkoff. 
for(string line; getline(in, line);)
    {
        stringstream iss(line);
        string FileType;

        getline(iss, FileType, '(');
        try{
            if(FileType == "snap")
            {
                getline(iss, ID, ',');
                getline(iss, name, ','); 
                getline(iss, address, ',');
                getline(iss, phone, ')');
                // cout << ID << endl;
                SnapV.push_back(new snap(stoi(ID), name, address, phone));
                out << line << endl;
            }
            else if(FileType == "csg"){
                getline(iss, course, ',');
                getline(iss, ID, ',');
                getline(iss, grade, ')');
                csgV.push_back(new csg(course, stoi(ID), grade));
                out << line << endl;
            }
            else if(FileType == "cdh")
            {
                getline(iss, course, ',');
                getline(iss, day, ',');
                getline(iss, time, ')');
                cdhV.push_back(new cdh(course, day, time));
                out << line << endl;
            }
            else if(FileType == "cr")
            {
                getline(iss, course, ',');
                getline(iss, room, ')');
                crV.push_back(new cr(course, room));
                out << line << endl;
            }
            else{
        throw line;
            }
        }
        catch (string e)
        {
            out << "**Error:" << e << '\n';
        }
        

    }


out << endl << "Vectors:" << endl;
for (unsigned int i = 0; i < SnapV.size(); i++)
{
   out << *SnapV[i] << endl;
}
for (unsigned int i = 0; i < csgV.size(); i++)
{
   out << *csgV[i] << endl;
}
for (unsigned int i = 0; i < cdhV.size(); i++)
{
   out << *cdhV[i] << endl;
}
for (unsigned int i = 0; i < crV.size(); i++)
{
   out << *crV[i] << endl;
}
out << endl;

// Course Grades:
// CS101,Charlie Brown,A
// CS101,Lucy,B
// CS101,Snoopy,A-

// EE200,Charlie Brown,C
// EE200,Linus,B+
// EE200,Snoopy,B

// PH100,Snoopy,A
// PH100,Lucy,C+

out << "Course Grades:" << endl; // use same strategy as student schedules

for(int i = 0; i < csgV.size(); ++i){
    for(int j = 0; j < SnapV.size(); ++j){
        if(csgV[i]->getID() == SnapV[j]->getID())
        {
            out << csgV[i]->getMain() << ","
                << SnapV[j]->getName() << "," 
                << csgV[i]->getGrade()
                << endl;
        }
    }
}
out << endl;


out << "Student Schedules:" << endl;
for(int i = 0; i < SnapV.size(); ++i){
    out << SnapV[i]->getName() << "," 
         << SnapV[i]->getID() << "," 
         << SnapV[i]->getAddress() << "," 
         << SnapV[i]->getPhone() << endl;
    for(int j = 0; j < csgV.size(); ++j){
        if(SnapV[i]->getID() == csgV[j]->getID())
        {
            string courseName = csgV[j]->getMain();
            out << " " << courseName << " ";
            for(int u = 0; u < cdhV.size(); u++){
                if(courseName == cdhV[u]->getMain()){
                    out << cdhV[u]->getDay();
                }
            }
            int count = 0;
            for(int a = 0; a < cdhV.size(); a++){
                if(courseName == cdhV[a]->getMain() && count < 1){
                    out << " " << cdhV[a]->getTime() << ", ";  
                    count++;                 
                }
            }
            for(int z = 0; z < crV.size(); z++){
                if(crV[z]->getMain() == courseName){
                    out << crV[z]->getRoom()
                    << endl;
                }
            }
        }
    }
out << endl;
}

for (cr* c : crV) {
    delete c;  
}
crV.clear(); 
for (snap* c : SnapV) {
    delete c;  
}
SnapV.clear(); 
for (csg* c : csgV) {
    delete c;  
}
csgV.clear(); 
for (cdh* c : cdhV) {
    delete c;  
}
cdhV.clear(); 
if (!CONSOLE) {
    delete &out;  
}

return 0;


}