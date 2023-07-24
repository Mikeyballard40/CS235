#ifndef MAZE_H
#define MAZE_H
#include "MazeInterface.h"
#include <string>

using namespace std;

class Maze : public MazeInterface
{
private:
	int ***array;
	int h;
	int w;
	int l;
	enum CellValue_t { OPEN, BLOCKED, VISITED, EXIT, LEFT, RIGHT, UP, DOWN, OUT, IN };

public: //layer is length
	Maze(int height, int width, int length) :
	h(height), w(width), l(length) {
		array = new int**[height];
        for (int i = 0; i < height; i++){
            array[i] = new int*[length];
            for (int j = 0; j < length; j++){
                array[i][j] = new int[width];
            }
        }
	}

	~Maze(void) {
		for (int hi = 0; hi < h; hi++) {
			for (int le = 0; le < l; le++) {
				delete[] array[hi][le];
			}
			delete[] array[hi];
		}
		delete[] array;
	}

	virtual bool funct(){
		return true;
	}


	/** Set maze value
	   @parm height
	   @parm width
	   @parm layer
	   @parm value
	*/
	virtual void setValue(int height, int width, int layer, int value){
		array[height][layer][width] = value;
	};


	/** Solve maze
	   @return true if solveable, else false
	*/
	virtual bool find_maze_path() {
		if (maze_path_finder(0, 0, 0) == true){
			return true;
		}
		return false;
	}


	bool maze_path_finder(int hi, int wi, int la){

		
			// CHANGE NAMES

		//track movement through maze
		int V = 2; //VISITED
		int OP = 0; //OPEN
		int B = 1; //BLOCKED

		//analysis of surrounding blocks in maze
		int L = (wi - 1); //LEFT
		int R = (wi + 1); //RIGHT
		int U = (hi - 1); //UP
		int D = (hi + 1); //DOWN
		int OU = (la - 1); //OUT
		int I = (la + 1); //IN

		if(hi > (h-1) || wi > (w-1) || la > (l-1) || hi < 0 || wi < 0 || la < 0){
			return false;
		}
		//if there is no solution
		else if(array[hi][la][wi] != OP){
			return false;
		}

		//find the end of the maze
		else if(hi== (h-1) && wi == (w-1) && la == (l-1)){
			array[hi][la][wi] = EXIT;
			return true;
		}

		//record block is open
		else if(array[hi][la][wi] == OP){
			array[hi][la][wi] = V;

			if( maze_path_finder(hi, L, la)){
				array[hi][la][wi] = LEFT;
				return true;
			}else if (maze_path_finder(hi, R, la)){
				array[hi][la][wi] = RIGHT;
				return true;
			}else if(maze_path_finder(U, wi, la)){
				array[hi][la][wi] = UP;
				return true;
			}else if(maze_path_finder(D, wi, la)){
				array[hi][la][wi] = DOWN;
				return true;
			}else if(maze_path_finder(hi, wi, OU)){
				array[hi][la][wi] = OUT;
				return true;
			}else if(maze_path_finder(hi, wi, I)){
				array[hi][la][wi] = IN;
				return true;
			}else{
				return false;
			}

		}else{
			return false;
		}

		};



	/** Output maze (same order as input maze)
	  @return string of 2D layers
	*/

	virtual std::string toString() const{
		string out;
		int count = 1;
		for (int le = 0; le < l; le++){
			out += "Layer ";
			out += std::to_string(count);
			out += "\n";
			count++;
			for (int hi = 0; hi < h; hi++)  {
				for (int wd = 0; wd < w; wd++) {
					if (array[hi][le][wd] == OPEN){
						out += "_ ";
					}else if (array[hi][le][wd] == BLOCKED){
						out += "X ";
					}else if (array[hi][le][wd] == VISITED){
						out += "* ";
					}else if (array[hi][le][wd] == EXIT){
						out += "E ";
					}else if (array[hi][le][wd] == LEFT){
						out += "L ";
					}else if (array[hi][le][wd] == RIGHT){
						out += "R ";
					}else if (array[hi][le][wd] == UP){
						out += "U ";
					}else if (array[hi][le][wd] == DOWN){
						out += "D ";
					}else if (array[hi][le][wd] == OUT){
						out += "O ";
					}else if (array[hi][le][wd] == IN){
						out += "I ";
					}
				}
				out += "\n";
			}
		}
		return out;
	};

};
#endif // MAZE_INTERFACE_H