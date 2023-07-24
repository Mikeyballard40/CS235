#include <iostream>
#include <string>
#include <vector> //
#include "Laptop.h"
using namespace std;

int main(int argc, char* argv[])
{
    vector<Computer*> computers;
    computers.push_back(new Computer("Acer", "I3", 8, 256));
    computers.push_back(new LapTop("HP", "I5", 16, 500, 13, 6.5));

    for(unsigned int i = 0; i < computers.size(); i++)
        cout << endl << computers[i]->toString() << endl;


    // Computer myComputer("HP", "I5", 16, 500);
    // LapTop yourComputer("Dell", "I7", 32, 1000, 15, 5);
    // cout << endl << "My Computer:" << endl << myComputer.toString() << endl;
    // cout << endl << "Your Computer:" << endl << yourComputer.toString() << endl;
    return 0;
    
}