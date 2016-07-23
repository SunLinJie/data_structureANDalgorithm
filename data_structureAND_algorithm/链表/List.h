#ifndef LIST_H
#define LIST_H
template <class Type>
class List;

template <class Type>
class ListIterator;

template <class Type>
class ListNode{
    friend class List<Type>;
    friend class ListIterator<Type>;
private:
    Type data;
    ListNode *link;
    ListNode(Type);
};


template <class Type>
ListNode<Type>::ListNode(Type element){
    data = element;
    link = 0;
}

template <class Type>
class List{
    friend class ListIterator<Type>;
public:
    List() {first = 0;}
    void Insert(Type);
    void Show();
    void Delete(Type k);
    void Invert();
    void Concatenate(List<Type>);
private:
    ListNode<Type> *first;
};

template <class Type>
void List<Type>::Insert(Type k){
    ListNode<Type> *newnode = new ListNode<Type> (k);
    newnode->link = first;
    first = newnode;
}

template<class Type>
void List<Type>::Show(){
    for (ListNode<Type> *current = first; current; current = current->link){
        std::cout << current->data;
        if (current->link)  std::cout << "->";
    }
    std::cout << std::endl;
}

template<class Type>
void List<Type>::Delete(Type k){
    ListNode<Type> *previous = 0;
    ListNode<Type> *current;
    for (current = first; current && current->data != k; previous = current, current = current->link){
        ;
    }
    if (current){
        if(previous) previous->link = current->link;
        else first = first->link;
        delete current;
    }
}

template <class Type>
void List<Type>::Invert(){
    ListNode<Type> *p = first, *q = 0;
    while(p){
        ListNode<Type> *r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;
}

template <class Type>
void List<Type>::Concatenate(List<Type> L)
{
    if(!first) { first = L.first; return;}
    if(L.first){
        ListNode<Type> *p;
        for(p = first; p->link; p = p->link) ; //kong xun huan
        p->link = L.first;
    }
}

template <class Type>
class ListIterator
{
public:
    ListIterator(const List<Type>& l):list(l), current(l.first){}
    bool NotNull();
    bool NextNotNull();
    Type* First();
    Type* Next();
private:
    const List<Type> &list;
    ListNode<Type>* current;
};


template <class Type>
bool ListIterator<Type>::NotNull()
{
    if (current) return true;
    else return false;
}

template <class Type>
bool ListIterator<Type>::NextNotNull()
{
    if(current && current->link) return true;
    else return false;
}

template <class Type>
Type* ListIterator<Type>::First()
{
    if(list.first) return &list.first->data;
    else return 0;
}

template <class Type>
Type* ListIterator<Type>::Next()
{
    if (current)
    {
        current = current->link;
        return &current->data;
    }
    else {
        return 0;
    }
}

#endif // LIST_H
