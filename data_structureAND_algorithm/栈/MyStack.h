#ifndef MYSTACK_H
#define MYSTACK_H

#include "MyUtil.h"

template <class T>
class MyStack
{
public:
    MyStack(int stackCapacity = 10);
    ~MyStack();
    bool IsEmpty() const;
    T& Top() const;
    void Push(const T& item);
    void Pop();

private:
    T *stack;
    int top;
    int capacity;
};

template <class T>
inline bool MyStack<T>::IsEmpty() const{
    return top == -1;
}

template<class T>
inline T& MyStack<T>::Top() const{
    if (IsEmpty()) throw "Stack is empty";
    return stack[top];
}

template <class T>
MyStack<T>::MyStack(int stackCapacity):capacity(stackCapacity){
    if (capacity < 1) throw "stack capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template <class T>
MyStack<T>::~MyStack(){
    delete[] stack;
}

template <class T>
void MyStack<T>::Push(const T &item){
    if (top == capacity -1){
        ChangeSize1D(stack, capacity, 2*capacity);
        capacity *= 2;
    }
    stack[++top] = item;
}

template <class T>
void MyStack<T>::Pop(){
    if (IsEmpty()) throw "Stack is empty";
    stack[top--].~T();   //very importance
}

#endif // MYSTACK_H
