#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BST<int> m;
    Element<int> a, b, c, d, e, f, g, h, i, j, k, l;
    a.key = 5;
    b.key = 3;
    c.key = 11;
    d.key = 3;
    e.key = 15;
    f.key = 2;
    g.key = 8;
    h.key = 22;
    i.key = 20;
    j.key = 9;

    cout << m.Insert(a) <<endl; //a = 5, root
    cout << m.Insert(b) <<endl;
    cout << m.Insert(c) <<endl;
    cout << m.Insert(d) <<endl;
    cout << m.Insert(e) <<endl;
    cout << m.Insert(f) <<endl;
    cout << m.Insert(g) <<endl;

    m.display();

    BSTNode<int> *p = m.Search(f);
    cout << p->data.key <<endl;

    BSTNode<int> *p2 = m.IterSearch(f);
    cout << p2->data.key <<endl;

    return 0;
}
