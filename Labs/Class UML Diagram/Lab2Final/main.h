#ifndef Main
#define Main
#include <string>
#include <sstream>
#include "snap.h"
using std::ostringstream;
using std::string;
using std::endl;
using namespace std;

class main
{
private:
    string course;
public:
    main(string c) :
    course(c) {}
    string getMain() const{ return course; }
    string toString() const 
    {
        ostringstream sb;
        sb << course << ",";
        return sb.str();
    }
    
    friend std::ostream& operator<< (ostream& os, const main& main)
    {
    os << main.toString();
    return os;
    }


};
#endif
