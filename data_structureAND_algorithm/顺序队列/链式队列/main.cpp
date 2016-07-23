#include <iostream>
#include "ListQueue.h"

using namespace std;

int main()
{
    ListQueue<int> myQ;
    for(int i = 0; i < 8; ++i){
        myQ.enQueue(i);
        while (!myQ.IsEmpty())
            cout << myQ.deQueue() <<endl;
    }

    return 0;
}
