#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Car.h"
#include "Deque.h"
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"
#include "Station.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
#define CONSOLE 0

using namespace std;


int main(int argc, char* argv[]){

int count = 0;

ifstream in(argv[1]);
ostream& out = CONSOLE ? cout : *(new ofstream(argv[2]));

Station<Car> stat;

for (string line; getline(in, line);)
{
    string item1, item2;
    istringstream iss(line);
    iss >> item1 >> item2;
    out << item1 << " " << item2 << " ";

    if (item1 == "Add:station"){
        count++;
        unsigned value = stoul(item2);
        out << stat.addCar(Car(value)) << endl; 
    }

    else if (item1 == "Add:stack"){
        out << stat.addStack() << endl;
    }

   else if (item1 == "Add:queue"){
        // out << endl << "*** Turntable: " << stat.XXX() << endl;
        out << stat.addQueue() << endl;
        // out << "*** Turntable: " << stat.XXX() << endl;

        // out << "TOPQUEUE: " << stat.queueToString() << endl;
    }
    
    else if (item1 == "Remove:station"){
        out << stat.removeCar() << endl;
    }

    else if (item1 == "Remove:stack"){
        out << stat.removeStack() << endl;
    }

    else if (item1 == "Remove:queue"){
        out << stat.removeQueue() << endl;
    }

    else if (item1 == "Top:station"){
        out << stat.topCar() << endl;
    }

    else if (item1 == "Top:stack"){
        out << stat.topStack() << endl;
    }

    else if (item1 == "Top:queue"){
        cout << "After Top:queue list of queue container: " << stat.queueToString() << endl;
        out << stat.topQueue() << endl;
    }

    else if (item1 == "Size:stack"){
        out << stat.sizeStack() << endl;
    }

    else if (item1 == "Size:queue"){
        out << stat.sizeQueue() << endl;
    }

    if (item1 == "Size:train"){
        out << stat.sizeTrain() << endl;
    }

    if (item1 == "Find"){
        unsigned value = stoul(item2);
        out << stat.find(value) << endl;
    }

    else if (item1 == "Queue"){
        if (stoi(stat.sizeQueue())!=0){

        }
        out << stat.queueToString() << endl;
    }

    else if (item1 == "Stack"){
        out << stat.stackToString() << endl;
    }

    else if (item1 == "Train"){
        out << stat.vectorToString() << endl;
    }


}


out.clear();
in.clear();
cout.clear();
if (!CONSOLE) {
    delete &out;
}


}
