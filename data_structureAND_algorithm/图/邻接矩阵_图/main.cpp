#include <iostream>
#define MAX_VERTS 20

using namespace std;

class Vertex
{
public:
    Vertex(char letter) {
        Label = letter;
    }
private:
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
private:
    Vertex * vertexList[MAX_VERTS];
    int nVerts;
    int adjMat[MAX_VERTS][MAX_VERTS];
};

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

    return 0;
}
