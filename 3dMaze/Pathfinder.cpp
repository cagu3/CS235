#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Pathfinder.h"

using namespace std;


	Pathfinder::Pathfinder() {
		srand(time(NULL));

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					currentMaze[k][j][i] = 1;
				}
			}
		}
	}
	Pathfinder::~Pathfinder() {

	}



	bool Pathfinder::validMaze() {

		if (tempMaze[0][0][0] != 1) {
			return false;
		}
		if (tempMaze[4][4][4] != 1) {
			return false;
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (tempMaze[k][j][i] == 1 || tempMaze[k][j][i] == 0) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}

		return true;
	}
	

	//Part 1-----------------------------------------------------------------------------------
	/*
	* toString
	*
	* Returns a string representation of the current maze. Returns a maze of all 1s if no maze
	* has yet been generated or imported.
	*
	* A valid string representation of a maze consists only of 125 1s and 0s (each separated
	* by spaces) arranged in five 5x5 grids (each separated by newlines) with no trailing newline. A valid maze must
	* also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
	*
	* Cell (0, 0, 0) is represented by the first number in the string representation of the
	* maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
	* number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
	* sixth number. Increasing in z means moving downward to a new grid, meaning cell
	* (0, 0, 1) is the twenty-sixth cell in the maze. Cell (4, 4, 4) is represented by the last number.
	*
	* Returns:		string
	*				A single string representing the current maze
	*/
	string Pathfinder::toString() const {
		string mazeStr = "";

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					stringstream ss;
					ss << currentMaze[k][j][i];
					mazeStr.append(ss.str());
					if (k < 4) {
						mazeStr.append(" ");
					}
				}
				mazeStr.append("\n");
			}
			if (i < 4) {
			mazeStr.append("\n");
			}
		}



		return mazeStr;
	}

	/*
	* createRandomMaze
	*
	* Generates a random maze and stores it as the current maze.
	*
	* The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
	* in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
	* solvable or unsolvable, and this method should be able to produce both kinds of mazes.
	*/
	void Pathfinder::createRandomMaze() {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					currentMaze[k][j][i] = rand() % 2;
				}
			}
		}

		currentMaze[0][0][0] = 1;
		currentMaze[4][4][4] = 1;

	}
	//-----------------------------------------------------------------------------------------

	//Part 2-----------------------------------------------------------------------------------
	/*
	* importMaze
	*
	* Reads in a maze from a file with the given file name and stores it as the current maze.
	* Does nothing if the file does not exist or if the file's data does not represent a valid
	* maze.
	*
	* The file's contents must be of the format described above to be considered valid.
	*
	* Parameter:	file_name
	*				The name of the file containing a maze
	* Returns:		bool
	*				True if the maze is imported correctly; false otherwise
	*/
	bool Pathfinder::importMaze(string file_name) {
		ifstream ifs;
		string s;

		ifs.open(file_name);
		if (ifs.fail()) {
			return false;
		}
		

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					stringstream ss;
					ifs >> s;
					ss << s;
					if (s.length() > 1) {
						return false;
					}
					ss >> tempMaze[k][j][i];
					if (ifs.fail()) {
						return false;
					}
				}
			}
		}

		
		if (validMaze()) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						currentMaze[k][j][i] = tempMaze[k][j][i];
					}
				}
			}
			return true;
		}
		else {
			return false;
		}



		ifs.close();

		return false;
	}






	bool Pathfinder::findPath(int x, int y, int z, vector<string>& slv) {
		stringstream ss;
		ss.clear();
		string s = "";
		ss << "(" << x << ", " << y << ", " << z << ")";
		s = ss.str();

		slv.push_back(s);

		if (x < 0 || x > 4 || y < 0 || y > 4 || z < 0 || z > 4) {
			slv.pop_back();
			return false;
		}
		if (currentMaze[x][y][z] == 0) {
			slv.pop_back();
			return false;
		}
		if (currentMaze[x][y][z] == 2) {
			slv.pop_back();
			return false;
		}

		if (x == 4 && y == 4 && z == 4) {
			return true;
		}

		//recurse
		if (currentMaze[x][y][z] == 1) {
			currentMaze[x][y][z] = 2;
		}	
		if (findPath(x,y+1,z,slv) || findPath(x,y-1,z,slv) || findPath(x-1,y,z,slv) || findPath(x+1,y,z,slv) || findPath(x,y,z+1,slv) || findPath(x,y,z-1,slv)) {
			return true;
		}
		else {
			slv.pop_back();
			return false;
		}




	}

	//-----------------------------------------------------------------------------------------

	//Part 3-----------------------------------------------------------------------------------
	/*
	* solveMaze
	*
	* Attempts to solve the current maze and returns a solution if one is found.
	*
	* A solution to a maze is a list of coordinates for the path from the entrance to the exit
	* (or an empty vector if no solution is found). This list cannot contain duplicates, and
	* any two consecutive coordinates in the list can only differ by 1 for only one
	* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
	* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
	* where x, y, and z are the integer coordinates of a cell.
	*
	* Understand that most mazes will contain multiple solutions
	*
	* Returns:		vector<string>
	*				A solution to the current maze, or an empty vector if none exists
	*/
	vector<string> Pathfinder::solveMaze() {
		vector<string> solve;


		findPath(0,0,0,solve);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (currentMaze[k][j][i] == 2) {
						currentMaze[k][j][i] = 1;
					}
				}
			}
		}


		return solve;
	}
















