#include <iostream>
#define MAX_VERTS 20
#include <stack>
#include <queue>

using namespace std;

class Vertex
{
public:
    Vertex(char letter) {
        Label = letter;
        wasVisited = false;
    }
    bool wasVisited;
    char Label;
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addVertex(char letter);
    void addEdge(int start, int end);
    void PrintMatrix();
    void showVertex(int v);
    void DFS();
    void BFS();
private:
    Vertex * vertexList[MAX_VERTS];
    int nVerts;
    int adjMat[MAX_VERTS][MAX_VERTS];

    int getAdjUnvisitedVertex(int v);
};


int Graph::getAdjUnvisitedVertex(int v)
{
    for(int i = 0; i < nVerts; i++)
        if((adjMat[v][i] == 1) && (vertexList[i]->wasVisited == false))
            return i;
    return -1;
}
//------------------------------------DFS----------------------------------------------//
void Graph::DFS()
{
    stack<int> gStack;
    vertexList[0]->wasVisited = true;  //from first index start
    showVertex(0);
    gStack.push(0);
    int v;
    while(gStack.size() > 0)
    {
        v = getAdjUnvisitedVertex(gStack.top());
        if(v == -1)
            gStack.pop();
        else
        {
            vertexList[v]->wasVisited = true;
            showVertex(v);
            gStack.push(v);
        }
    }

    cout << endl;

    for(int i = 0; i < nVerts; i++)
        vertexList[i]->wasVisited = false;   //ke yi jin xing duo ci sou suo !
}
//------------------------------------------------------------------------------------//
//--------------------------------------BFS------------------------------------------//
void Graph::BFS()
{
    queue<int> gQueue;
    vertexList[0]->wasVisited = true;
    showVertex(0);
    gQueue.push(0);
    int vert1, vert2;
    while(gQueue.size() > 0)
    {
        vert1 = gQueue.front();
        gQueue.pop();
        vert2 = getAdjUnvisitedVertex(vert1);
        while(vert2 != -1)
        {
            vertexList[vert2]->wasVisited = true;
            showVertex(vert2);
            gQueue.push(vert2);

            vert2 = getAdjUnvisitedVertex(vert1);
        }
    }
    cout << endl;
    for ( int i = 0; i < nVerts; i++)
        vertexList[i]->wasVisited = false;
}
//--------------------------------------------------------------------------------------//
void Graph::showVertex(int v)  //vertex index
{
    cout << vertexList[v]->Label << " ";
}

Graph::Graph()
{
    nVerts = 0;
    for(int i = 0; i < MAX_VERTS; i++)
        for(int j = 0; j < MAX_VERTS; j++)
            adjMat[i][j] = 0;
}

void Graph::addVertex(char letter)
{
    vertexList[nVerts++] = new Vertex(letter);
}

void Graph::addEdge(int start, int end)
{
    adjMat[start][end] = 1;
    adjMat[end][start] = 1;
}

void Graph::PrintMatrix()
{
    for(int i = 0; i < nVerts; i++)
    {
        for (int j = 0; j < nVerts; j++)
            cout << adjMat[i][j] << " ";
    cout << endl;
    }
}

Graph::~Graph()
{
    for (int i= 0; i < nVerts; i++)
        delete vertexList[i];
}

int main()
{
    Graph g;

    g.addVertex('A');  // 0
    g.addVertex('B');  // 1
    g.addVertex('C');  // 2
    g.addVertex('D');  // 3
    g.addVertex('E');  // 4

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 2);
    g.addEdge(4, 1);

    g.PrintMatrix();

    g.DFS();
    g.BFS();

    return 0;
}
