#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <utility>
#include "solve.h"
#include "vertex.h"

using namespace std;

string solve(string maze) {
	unordered_map<int, Vertex*> vertexMap;
	string solvedMaze = "";
	size_t rowLength = maze.find('\n') + 1;
	int counter = 0;
	int xCoor = 0;
	int yCoor = 0;
	int xWidth = rowLength - 1;
	int yHeight = 0;
	while (counter < maze.size()) {		// Runs in O(s) time
		// Create vertices for each open space in the maze
		char curr = maze[counter];
		if (curr == ' ') {
			vertexMap[counter] = new Vertex(yCoor, xCoor);
			if (xCoor > 0 && maze[counter - 1] == ' ') {		// Left neighbor
				vertexMap[counter]->neighs.push_back(vertexMap[counter - 1]);
				vertexMap[counter - 1]->neighs.push_back(vertexMap[counter]);
			}
			if (yCoor > 0 && maze[counter - rowLength] == ' ') {		// Top neighbor
				vertexMap[counter]->neighs.push_back(vertexMap[counter - rowLength]);
				vertexMap[counter - rowLength]->neighs.push_back(vertexMap[counter]);
			}
			//solvedMaze += ' ';
			xCoor++;
		}
		else if (curr == '\n') {
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

	Vertex* startVertex = nullptr;
	Vertex* endVertex = nullptr;
	unordered_set<Vertex*> marked;
	queue<Vertex*> Q;

	for (const auto& pair : vertexMap) {		// Runs in O(s) time
		if (pair.second->row == 0 || pair.second->row == yHeight - 1 ||
			pair.second->col == 0 || pair.second->col == xWidth - 1) {
			if (startVertex == nullptr) {
				startVertex = pair.second;
			}
			else {
				endVertex = pair.second;
			}
		}
	}
	

	return solvedMaze;
}