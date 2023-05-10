#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    // open argv[1] or cin for input
    istream& in = (argc >  1) ? *(new ifstream(argv[1])) : cin;
    if (!in) return 1;

    // open argv[2] or cout for output
    ostream& out = (argc ? > 2) ? *(new ofstream(argv[2])) : cout
    if (!out) return 2;

    //read input file lines and send to output file
    for (string line; getline(in, line);)
    {
        out << line << endl;
    }
    // **MEMORY LEAK**
    int* memory = new int(100)

    // recover input/output object memory
    if (&in != &cin) delete(&in);
    if (&out != &cout) delete(&out);

    return 0
}