#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int NODE_COUNT = 10;


class Graph
{
    
public:

    Graph();

    Graph(bool adjM[][NODE_COUNT]);
    
    bool createEdge(int u, int v);
    
    bool isAdjacent(int u, int v);
    
    bool markVertex(int u);
    
    bool isMarked(int u);
    
    void unmarkAll();
    
    void BFS();

    void DFS();

private:
    
    bool *markedVertices;
    bool **adjacencyMatrix;

    void DFS(int x);

};
    
