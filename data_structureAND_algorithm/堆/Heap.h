#ifndef HEAP_H
#define HEAP_H

template <class T>
class MaxHeap
{
public:
    MaxHeap(int mx = 10);
    virtual ~MaxHeap();

    bool IsEmpty();
    void Push(const T&);
    void Pop();
    const T& Top() const;
private:
    T* heapArray;
    int maxSize;
    int currentSize;

    void trickleUp(int index);
    void trickleDown(int index);
};

template <class T>
MaxHeap<T>::MaxHeap(int mx)
{
    if(mx < 1) throw "max size must be >= 1";

    maxSize = mx;
    currentSize = 0;
    heapArray = new T[maxSize];
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
    delete[] heapArray;
}

template <class T>
bool MaxHeap<T>::IsEmpty()
{
    return currentSize == 0;
}

template <class T>
void MaxHeap<T>::Push(const T& e)
{
    if(currentSize == maxSize) throw "MaxHeap is full.";

    heapArray[currentSize] = e;
    trickleUp(currentSize);
    currentSize++;
}

template <class T>
void MaxHeap<T>::Pop()
{
    heapArray[0] = heapArray[--currentSize];
    trickleDown(0);
}

template <class T>
void MaxHeap<T>::trickleUp(int index)
{
    int parent = (index - 1)/2;
    T bottom = heapArray[index];
    while(index > 0 && heapArray[parent] < bottom)     /////////
    {
        heapArray[index] = heapArray[parent];
        index = parent;
        parent = (parent - 1)/2;
    }
    heapArray[index] = bottom;
}

template <class T>
const T& MaxHeap<T>::Top() const
{
    return heapArray[0];
}

template <class T>
void MaxHeap<T>::trickleDown(int index)
{
    int largerChild;
    T top = heapArray[index];
    while( index < currentSize/2)    ///////////////////
    {
        int leftChild = 2 * index + 1;
        int rightChild = leftChild + 1;
        if(rightChild < currentSize && heapArray[leftChild] < heapArray[rightChild])
            largerChild = rightChild;
        else
            largerChild = leftChild;

        if( top >= heapArray[largerChild])
            break;
        heapArray[index] = heapArray[largerChild];
        index = largerChild;
    }
    heapArray[index] = top;
}

#endif // HEAP_H
