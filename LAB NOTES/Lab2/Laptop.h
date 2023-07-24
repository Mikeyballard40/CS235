#ifndef laptop
#define laptop
#include <string>
#include <sstream>
#include "Computer.h"
using std::ostringstream;
using std::string;
using std::endl;

class LapTop : public Computer
{
private:
    int screenSize;
    double weight;
public:
    LapTop(const string& m, const string& p, int r, int d, int s, double w) :
        Computer(m, p, r, d),
        screenSize(s), weight(w) {}
    int getScreenSize() const { return screenSize; }
    int getDiskSIze() const { return weight; };
};
#endif