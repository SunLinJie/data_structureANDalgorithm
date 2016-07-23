#ifndef STACK_H
#define STACK_H

template <class T> class Stack;

template <class T>
class ChainNode{
    friend class Stack<T>;

private:
    ChainNode(const T& thedata, ChainNode *n = 0):data(thedata), link(n){}
    T data;
    ChainNode<T> *link;
};

template <class T>
class Stack{
public:
    Stack():top(0){}
    ~Stack() { MakeEmpty();}
    bool IsEmpty() const;
    T& Top() const;
    void Push(const T& e);
    void Pop();
    void MakeEmpty();
private:
    ChainNode<T> *top;
};

template <class T>
bool Stack<T>::IsEmpty() const{
    return top == 0;
}

template <class T>
void Stack<T>::Push(const T &e){
    top = new ChainNode<T>(e, top);
}

template <class T>
T& Stack<T>::Top() const{
    if (this->IsEmpty())
        throw "Stack is empty";
    else
        return top->data;
}

template <class T>
void Stack<T>::Pop(){
    if (this->IsEmpty())
        throw "Stack is empty";
    ChainNode<T> *delNode = top;
    top = top->link;
    delete delNode;  //
}

template <class T>
void Stack<T>::MakeEmpty()
{
    while(! IsEmpty())
        Pop();
}

#endif // STACK_H
