#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<char> q(5);

    q.Push('A');
    q.Push('B');
    q.Push('C');
    cout << q.Front() << ", " << q.Rear() <<endl;
    q.Push('D');
    q.Push('E');

    q.Pop();
    cout << q.Front() << ", " << q.Rear() <<endl;

    return 0;
}
