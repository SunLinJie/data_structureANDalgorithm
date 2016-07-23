#include <iostream>
#include "List.h"
#include <list> //c++ stl

using namespace std;

int main()
{
    List<int> intList;

    intList.Insert(5);
    intList.Insert(15);
    intList.Insert(25);
    intList.Insert(35);

    ListIterator<int> li(intList);
    if(li.NotNull())
    {
        cout << *li.First();
        while(li.NextNotNull())
            cout << "->" << *li.Next();
        cout << endl;
    }

    ListIterator<int> iter(intList);
    cout << *iter.First() << endl;
    cout << *iter.Next() <<endl;
    cout << *iter.Next() <<endl;
    cout << *iter.Next() <<endl;
    cout << *iter.Next() <<endl;
    cout << *iter.Next() <<endl;
    return 0;
}
