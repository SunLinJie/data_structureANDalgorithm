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
    ListNode() {}
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
    List() {first = new ListNode<Type>; first->link = first;}
    void Insert(Type);
//    void Show();
    void Delete(Type k);
//    void Invert();
//    void Concatenate(List<Type>);
private:
    ListNode<Type> *first;
};

template <class Type>
void List<Type>::Insert(Type k){
    ListNode<Type> *newnode = new ListNode<Type> (k);
    newnode->link = first->link;
    first->link = newnode;
}

//template<class Type>
//void List<Type>::Show(){
//    for (ListNode<Type> *current = first; current; current = current->link){
//        std::cout << current->data;
//        if (current->link)  std::cout << "->";
//    }
//    std::cout << std::endl;
//}

template<class Type>
void List<Type>::Delete(Type k){
    ListNode<Type> *previous = first;
    ListNode<Type> *current;
    for (current = first->link; current != first && current->data != k; previous = current, current = current->link){
        ;
    }
    if (current != first){
        //if(previous) previous->link = current->link;
        //else first = first->link;
        previous->link = current->link;
        delete current;
    }
}

//template <class Type>
//void List<Type>::Invert(){
//    ListNode<Type> *p = first, *q = 0;
//    while(p){
//        ListNode<Type> *r = q;
//        q = p;
//        p = p->link;
//        q->link = r;
//    }
//    first = q;
//}

//template <class Type>
//void List<Type>::Concatenate(List<Type> L)
//{
//    if(!first) { first = L.first; return;}
//    if(L.first){
//        ListNode<Type> *p;
//        for(p = first; p->link; p = p->link) ; //kong xun huan
//        p->link = L.first;
//    }
//}

template <class Type>
class ListIterator
{
public:
    ListIterator(const List<Type>& l):list(l), current(l.first->link){}
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
    if (current != list.first) return true;
    else return false;
}

template <class Type>
bool ListIterator<Type>::NextNotNull()
{
    if(current->link != list.first) return true;
    else return false;
}

template <class Type>
Type* ListIterator<Type>::First()
{
    if(current != list.first) return &current->data;
    else return 0;
}

template <class Type>
Type* ListIterator<Type>::Next()
{

    current = current->link;
    if(current == list.first) current = current->link;
    return &current->data;
}

#endif // LIST_H
