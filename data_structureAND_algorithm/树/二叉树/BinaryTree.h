#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <queue>

template <class T> class BinaryTree;

template <class T>
class TreeNode
{
public:
    TreeNode(){
        leftChild = NULL;
        rightChild = NULL;
    }

    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template <class T>
class BinaryTree
{
public:
    void InOrder();
    void InOrder(TreeNode<T>* currentNode);
    void PreOrder();
    void PreOrder(TreeNode<T>* currentNode);
    void PostOrder();
    void PostOrder(TreeNode<T>* currentNode);
    void LevelOrder();
    void Visit(TreeNode<T>* currentNode);

    TreeNode<T> *root;
};

template <class T>
void BinaryTree<T>::Visit(TreeNode<T> *currentNode)
{
    std::cout << currentNode->data;
}

template <class T>
void BinaryTree<T>::InOrder()
{
    InOrder(root);
}

template <class T>
void BinaryTree<T>::PreOrder()
{
    PreOrder(root);
}

template <class T>
void BinaryTree<T>::PostOrder()
{
    PostOrder(root);
}

template <class T>
void BinaryTree<T>::LevelOrder()
{
    std::queue<TreeNode<T>*> q;
    TreeNode<T>* currentNode = root;
    while(currentNode){
        Visit(currentNode);
        if(currentNode->leftChild) q.push(currentNode->leftChild);
        if(currentNode->rightChild) q.push(currentNode->rightChild);
        if (q.empty()) return;
        currentNode = q.front();
        q.pop();
    }
}

template <class T>
void BinaryTree<T>::InOrder(TreeNode<T>* currentNode)
{
    if(currentNode){
        InOrder(currentNode->leftChild);
        Visit(currentNode);
        InOrder(currentNode->rightChild);
    }
}

template <class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode)
{
    if(currentNode){
        Visit(currentNode);
        PreOrder(currentNode->leftChild);
        PreOrder(currentNode->rightChild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
    if(currentNode){
        PostOrder(currentNode->leftChild);
        PostOrder(currentNode->rightChild);
        Visit(currentNode);
    }
}
#endif // BINARYTREE_H
