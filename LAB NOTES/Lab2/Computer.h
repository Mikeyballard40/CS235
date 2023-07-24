#ifndef computer
#define computer
#include <string>
#include <sstream>
using std::ostringstream;
using std::string;
using std::endl;

class Computer
{
private:
    string manufacturer;
    string processor;
    int ramSize;
    int diskSize;
public:
    Computer(const string& m, const string& p, int r, int d) :
        manufacturer(m), processor(p), ramSize(r), diskSize(d) {}
    int getRamSize() const { return ramSize; }
    int getDiskSIze() const { return diskSize; }
    virtual string toString() const
    {
    ostringstream sb;
    sb << "Manufacturer: " << manufacturer
       << endl << "CPU: " << processor
       << endl << "RAM: " << ramSize << " Mbs"
       << endl << "Disk: " << diskSize << " Gbs";
    return sb.str();
    }
};
#endif