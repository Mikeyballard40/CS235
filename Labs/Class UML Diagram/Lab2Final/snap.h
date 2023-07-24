#ifndef Snap
#define Snap
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using std::ostringstream;
using std::string;
using std::endl;
using namespace std;

class snap
{
private:
    int ID;
    string name;
    string address;
    string phone;
public:
    snap(const int I, const string n, string a, string p) :
        ID(I), name(n), address(a), phone(p) {}
    int getID() const { return ID; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    string getPhone() const { return phone; }
    string toString() const 
    {
        ostringstream sb;
        sb << "snap(" << setfill('0') << setw(4) << ID << "," 
                      << name << ","
                      << address << ","
                      << phone << ")";
        return sb.str();
    }
    
    friend std::ostream& operator<< (ostream& os, const snap& snap)
    {
    os << snap.toString();
    return os;
    }
    

};


#endif
