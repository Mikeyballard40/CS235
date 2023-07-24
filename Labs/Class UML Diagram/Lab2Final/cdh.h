#ifndef Cdh
#define Cdh
#include <string>
#include <sstream>
#include "csg.h"
using std::ostringstream;
using std::string;
using std::endl;
using namespace std;

class cdh : public main
{
private:
    string Course;
    string Day;
    string Time;
public:
    cdh(string c, string d, string t) :
        main(c), 
        Course(c),
        Day(d), Time(t) {}
    string getDay() const { return Day; }
    string getTime() const { return Time; }
    string toString() const 
    {
        ostringstream sb;
        sb << "cdh(" << Course << ","
                     << Day << ","
                     << Time << ")";
        return sb.str();
    }
    
    friend std::ostream& operator<< (ostream& os, const cdh& cdh)
    {
    os << cdh.toString();
    return os;
    }

};
#endif


