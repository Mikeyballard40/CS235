#ifndef Csg
#define Csg
#include <string>
#include <sstream>
#include "main.h"
#include <iomanip>
#include <iostream>
using std::ostringstream;
using std::string;
using std::endl;
using namespace std;

class csg : public main
{
private:
    string course;
    int ID;
    string grade;
public:
    csg(string c, int i, string g) :
        main(c),
        course(c), ID(i), grade(g) {}
    string getGrade() const { return grade; }
    int getID() const { return ID; }
    string toString() const 
    {
        ostringstream sb;
        sb << "csg(" << course << ","
                     << setfill('0') << setw(4) << ID << ","
                     << grade << ")";
        return sb.str();
    }
    
    friend std::ostream& operator<< (ostream& os, const csg& csg)
    {
    os << csg.toString();
    return os;
    }
};
#endif

