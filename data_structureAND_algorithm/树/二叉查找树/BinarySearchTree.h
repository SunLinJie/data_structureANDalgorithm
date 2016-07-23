#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

enum Boolean {FALSE, TRUE};

template <class T>
class Element
{
public:
    T key;
};

template <class T> class BST;

template <class T>
class BSTNode
{
    friend class BST<T>;
public:
    Element<T> data;
    BSTNode<T>* LeftChild;
    BSTNode<T>* RightChild;
    void display(int i);
};

template <class T>
class BST
{
public:
    BST(BSTNode<T> *init = 0)
    {
        root = init;
    }
    Boolean Insert(const Element<T>& x);
    BSTNode<T>* Search(const Element<T>& x);
    BSTNode<T>* Search(BSTNode<T> *, const Element<T>&);
    BSTNode<T>* IterSearch(const Element<T>&);
    void display()
    {
        std::cout << "\n";
        if(root)
            root->display(1);
        else
            std::cout << "This is null tree!";
    }

private:
    BSTNode<T> *root;
};


template <class T>
void BSTNode<T>::display(int i)
{
    std::cout << "Position: " << i << "; data.key = " << data.key << "\n";
    if(LeftChild) LeftChild->display(2*i);
    if(RightChild) RightChild->display(2*i+1);
}

template <class T>
Boolean BST<T>::Insert(const Element<T> &x)
{
    BSTNode<T> *p = root;
    BSTNode<T> *q = 0;

    //first find position
    while(p){
        q = p;
        if(x.key == p->data.key) return FALSE;
        if(x.key < p->data.key)
            p = p->LeftChild;
        else
            p = p->RightChild;
    }

    p = new BSTNode<T>;
    p->LeftChild = p->RightChild = 0;
    p->data = x;

    if(!root) root = p;
    else if(x.key < q->data.key) q->LeftChild = p;
    else q->RightChild = p;
    return TRUE;
}

template <class T>
BSTNode<T>* BST<T>::Search(const Element<T> &x)
{
    return Search(root, x);
}

template <class T>
BSTNode<T>* BST<T>::Search(BSTNode<T> * b, const Element<T> &x)
{
    if(!b) return 0;
    if(x.key == b->data.key) return b;
    if(x.key < b->data.key) return Search(b->LeftChild, x);
    return Search(b->RightChild, x);
}

template <class T>
BSTNode<T>* BST<T>::IterSearch(const Element<T> &x)
{
    for (BSTNode<T>* t = root; t; )
    {
        if (x.key == t->data.key) return t;
        if(x.key < t->data.key)
            t = t->LeftChild;
        else
            t = t->RightChild;
    }
    return 0;
}

#endif // BINARYSEARCHTREE_H
