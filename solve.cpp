#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include "solve.h"
#include "vertex.h"

using namespace std;

string solve(string maze) {
	unordered_map<char, Vertex*> vertexMap;
	string solvedMaze = "";
	int counter = 0;
	int xCoor = 0;
	int yCoor = 0;
	int xWidth = 0;
	int yHeight = 0;
	while (counter < maze.size()) {		// Create vertices for each open space in the maze
		char curr = maze[counter];
		if (curr == ' ') {
			vertexMap[curr] = new Vertex(yCoor, xCoor);
			//solvedMaze += ' ';
			xCoor++;
		}
		else if (curr == '\n') {
			xWidth = xCoor;
			yCoor++;
			xCoor = 0;
			//solvedMaze += curr;
		}
		else {
			xCoor++;
			//solvedMaze += curr;
		}
		counter++;
	}
	yHeight = yCoor;

	//cout << "Map is width: " << xWidth << " and Height: " << yHeight << endl;

	// Create edges between neighboring vertices

	return solvedMaze;
}