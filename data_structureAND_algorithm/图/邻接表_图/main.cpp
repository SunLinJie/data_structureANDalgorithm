#include <iostream>
#include <list>

using namespace std;

class Vertex
{
public:
    char Label;
    Vertex(char lab) { Label = lab;}
};

ostream& operator <<(ostream& out, const Vertex& v)
{
    cout << v.Label;
    return out;
}

template <class T>
class Graph
{
public:
    Graph(const int vertices):n(vertices)
    {
        VertexList = new T*[n];
        HeadNodes = new list<int>[n];
        nVerts = 0;
    }

    ~Graph()
    {
        delete[] VertexList;
        delete[] HeadNodes;
    }

    void addVertex(T *v);
    void addEdge(int start, int end);
    void PrintVertice();
    void PrintAdjList();

private:
    T** VertexList;
    list<int>* HeadNodes;
    int n;
    int nVerts;
};

template <class T>
void Graph<T>::addVertex(T *v)
{
    VertexList[nVerts++] = v;
}

template <class T>
void Graph<T>::addEdge(int start, int end)
{
    HeadNodes[start].push_back(end);
}

template <class T>
void Graph<T>::PrintVertice()
{
    for (int i = 0; i < nVerts; i++)
        cout << *VertexList[i] << " ";
    cout << endl;
}

template <class T>
void Graph<T>::PrintAdjList()
{
    for (int i = 0; i < nVerts; i++)
    {
        cout << i << "->";
        for(list<int>::iterator iter = HeadNodes[i].begin(); iter != HeadNodes[i].end(); ++iter)
            cout << *iter << "->";
        cout << "end" <<endl;
    }
}

int main()
{
//    Graph<char> g(5);
//    char a = 'A';
//    char b = 'B';
//    char c = 'C';
//    char d = 'D';
//    char e = 'E';

    Graph<Vertex> g(5);
    Vertex a('A');
    Vertex b('B');
    Vertex c('C');
    Vertex d('D');
    Vertex e('E');

    g.addVertex(&a);
    g.addVertex(&b);
    g.addVertex(&c);
    g.addVertex(&d);
    g.addVertex(&e);


    g.PrintVertice();

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 3);

    g.PrintAdjList();
    return 0;
}
