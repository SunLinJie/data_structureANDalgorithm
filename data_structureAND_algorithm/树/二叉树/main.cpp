#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<char> tree;
    TreeNode<char> a, b, c, d, e, f, g, h, i;

    a.data = 'A';
    b.data = 'B';
    c.data = 'C';
    d.data = 'D';
    e.data = 'E';
    f.data = 'F';
    g.data = 'G';
    h.data = 'H';
    i.data = 'I';

    tree.root = &a;
    a.leftChild = &b;
    a.rightChild = &f;
    b.leftChild = &c;
    b.rightChild = &g;
    c.leftChild = &d;
    c.rightChild = &h;
    d.leftChild = &e;
    d.rightChild = &i;

    tree.InOrder();
    cout << endl;
    tree.PreOrder();
    cout << endl;
    tree.PostOrder();
    cout << endl;
    tree.LevelOrder();
    cout << endl;

    return 0;
}
