#include "graph.h"

Graph::Graph()
{
    //Create two dynamic arrays, the adjacency
    //matrix to store the graph and the marked
    //set --- initialized to false for all to start
    //The adjacent matrix is all false, it is an
    //empty graph.
    
    adjacencyMatrix = new bool*[NODE_COUNT];
    markedVertices = new bool[NODE_COUNT];

    // a loop to create all rows (vertices) an inner
    //loop to create the adjacent vertices (columns)
    //intialized to empty graph
    for(int i=0; i < NODE_COUNT; i++)
    {
        adjacencyMatrix[i] = new bool[NODE_COUNT];
            for (int j=0; j < NODE_COUNT; j++)
            {
                adjacencyMatrix[i][j] = false;
            }
        markedVertices[i]=false;
        
    }
}


Graph::Graph(bool adjM[][NODE_COUNT])
{
    //Create two dynamic arrays, the adjacency
    //matrix to store the graph and the marked
    //set --- initialized to false for all to start
    
    
    adjacencyMatrix = new bool*[NODE_COUNT];
    markedVertices = new bool[NODE_COUNT];
    
    
    // a loop to create all rows (vertices) an inner
    //loop to create the adjacent vertices (columns)
    //intialized to empty graph
    for(int i=0; i < NODE_COUNT; i++)
    {
        adjacencyMatrix[i] = new bool[NODE_COUNT];
        for (int j=0; j < NODE_COUNT; j++)
        {
            adjacencyMatrix[i][j] = adjM[i][j];
        }
        markedVertices[i]=false;
        
    }
}


bool Graph::createEdge(int u, int v)
{
    //if u and v are in bounds then add the edge and return true
    //if edge has been previously added, nothing happens, if
    //out of nounds returns false
    if(u >=0 && u <= NODE_COUNT && v >= 0 && v <= NODE_COUNT)
    {
        adjacencyMatrix[u][v] = true;
        adjacencyMatrix[v][u] = true;
        return true;
    }
    return false;
}



//returns true if there is an edge between
//u and v
bool Graph::isAdjacent(int u, int v)
{
    return adjacencyMatrix[u][v];
}

//marks a vertex true --- public
//could be private
bool Graph::markVertex(int u)
{
    if (u >= 0 && u <= NODE_COUNT)
    {
        markedVertices[u]=true;
        return true;
    }
    return false;
}



bool Graph::isMarked(int u)
{
    return markedVertices[u];
}




//unmark all vertices, also could be
//private
void Graph::unmarkAll()
{
    for (int i = 0; i < NODE_COUNT; i++) {
        markedVertices[i] = false;
    }
}



//BREAD FIRST SEARCH
void Graph::BFS()
{
    int u = 0;
    unmarkAll();
    markVertex(u);
    queue<int> q;
    q.push(u);
    cout << q.front() << " ";

    while (!q.empty()) {
        
        u = q.front();
        q.pop();
        
        for (int w = 0; w < NODE_COUNT; w++) {

            if (isAdjacent(u, w) && !isMarked(w)) {
                cout << w << " ";
                markVertex(w);
                q.push(w);
            }
        }
    }
	
    cout << endl;
}


//DEPTH FIRST SEARCH

void Graph::DFS()
{
    unmarkAll();
    int u = 0;
    markVertex(u);
    //cout << u << " ";

    DFS(u);


}

void Graph::DFS(int x)
{
    cout << x << " ";    
    for (int i = 0; i < NODE_COUNT; i++) {
        
        if (isAdjacent(x, i) && !isMarked(i)) {
           
            markVertex(i);
            DFS(i);
        }
    }
}

