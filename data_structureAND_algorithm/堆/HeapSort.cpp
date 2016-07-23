#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    MaxHeap<int> h(100);
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 1};

    for(int i = 0; i < 10; i++)
        h.Push(arr[i]);

    for (int i = 0; i < 10; i++)
    {    arr[i] = h.Top();
        h.Pop();
    }

    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
