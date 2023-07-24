#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ostream>
#include "Maze.h"


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

    

    ifstream in(argv[1]);
    ofstream out(argv[2]);
    int length, width, height;
        in >> height >> width >> length;
        Maze maz(height, width, length);

    //store the values from input file in array
    for (int l = 0; l < length; l++) {
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                int value = 0;
                in >> value;
                maz.setValue(h, w, l, value);
            }
        }
    }

    //out all values in array
    out << "Solve Maze:" << endl;
    out << maz.toString();


    if(maz.find_maze_path()){
        maz.find_maze_path();
        out << endl << "Solution:" << endl;
        out << maz.toString();
    }else if(!maz.find_maze_path()){
        out << endl << "No Solution Exists!";
    }


out.close();
return 0;
}


// *** NOTES ***

/**
left (width - 1) L
right (width + 1) R
up (height - 1) U
down (height + 1) D
out (layer - 1) O
in (layer + 1) I

*/