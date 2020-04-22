#pragma once
#include <vector>

using namespace std;

class GraphEdge {
public :
	int Head;
	int Tail;
	int weight;
};

class Graph {
public:
	vector<int> Node;
	vector<GraphEdge> Edge;
	int CurrentNodeCount;
};
