#ifndef Cr
#define Cr
#include <string>
#include <sstream>
#include "main.h"
using std::ostringstream;
using std::string;
using std::endl;
using namespace std;

class cr : public main
{
private:
    string course;
    string room;
public:
    cr(string c, string r) :
        main(c),
        course(c),
        room(r){}
    string getRoom() const { return room; }
    string toString() const 
    {
        ostringstream sb;
        sb << "cr(" << course << ","
                     << room << ")";
        return sb.str();
    }
    
    friend std::ostream& operator<< (ostream& os, const cr& cr)
    {
    os << cr.toString();
    return os;
    }
};
#endif
