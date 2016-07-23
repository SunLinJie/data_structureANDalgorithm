#include <iostream>

using namespace std;

class List;

class Node
{
private:
    int data;  //data field
    Node* link; //pointer filed
friend class List;
};

class List
{
public:
    void test();
    void show();
private:
    Node* first;
};

void List::test()
{
    Node *f = new Node();
    f->data = 44;
    f->link = 0;

    first = f;

    f = new Node();
    f->data = 72;
    f->link = 0;

    first->link = f;

    f = new Node();
    f->data = 210;
    f->link = 0;

    first->link->link = f;
}

void List::show()
{
    cout << first->data << "->"
         << first->link->data << "->"
         << first->link->link->data <<endl;
}

int main()
{
    List L;
    L.test();
    L.show();

    return 0;
}
