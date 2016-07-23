#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

template <class T>
class Queue
{
public:
    Queue(int queueCapacity = 10);
    bool IsEmpty() const;
    T& Front() const;
    T& Rear() const;
    void Push(const T& item);
    void Pop();

private:
    T *queue;
    int front;
    int rear;
    int capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{
     if (capacity < 1) throw "Queue capacity must be > 0";
     queue = new T[capacity];
     front = rear = 0;
}


template <class T>
inline bool Queue<T>::IsEmpty() const{
    return front == rear;
}

template <class T>
void Queue<T>::Push(const T &item){
//    if (rear == capacity - 1)
//        rear = 0;
//    else
//        rear++;


    rear = (rear + 1) % capacity;  //gao jie xie fa!
    queue[rear] = item;
}

template <class T>
inline T& Queue<T>::Front() const{
    if (IsEmpty()) throw "Queue is empty. NO front element";
    return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const{
    if (IsEmpty()) throw "Queue is empty.";
    return queue[rear];
}

template <class T>
void Queue<T>::Pop(){
    if(IsEmpty()) throw "Queue is empty.";
    front = (front + 1) % capacity;
    queue[front].~T();
}

#endif // QUEUE_H
