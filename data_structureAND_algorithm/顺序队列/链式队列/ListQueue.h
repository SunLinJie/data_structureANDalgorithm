#ifndef LINKQUEUE_H
#define LINKQUEUE_H

template <class T>
class ListQueue{
public:
    ListQueue();
    ~ListQueue();

    bool IsEmpty() const;
    const T& getFront() const;
    void enQueue(const T & x);
    T deQueue();
    void MakeEmpty();
private:
    struct ListNode
    {
        T element;
        ListNode *next;

        ListNode(const T & theElement, ListNode *n = 0):element(theElement), next(n){}
    };
    ListNode *front;
    ListNode *back;
};

template <class T>
ListQueue<T>::ListQueue()
{
    front = back = 0;
}

template <class T>
ListQueue<T>::~ListQueue()
{
    MakeEmpty();
}

template <class T>
void ListQueue<T>::MakeEmpty()
{
    while(!IsEmpty())
        deQueue();
}

template <class T>
bool ListQueue<T>::IsEmpty() const
{
    return front == 0;
}

template <class T>
const T & ListQueue<T>::getFront() const{
    if(IsEmpty())
        throw "Queue is empty";
    return front->element;
}

template <class T>
void ListQueue<T>::enQueue(const T &x)
{
    if (IsEmpty())
        back = front = new ListNode(x);
    else
        back = back->next = new ListNode(x);
}

template <class T>
T ListQueue<T>::deQueue(){
    T frontItem = getFront();

    ListNode *old = front;
    front = front->next;
    delete old;

    return frontItem;
}

#endif // LINKQUEUE_H
