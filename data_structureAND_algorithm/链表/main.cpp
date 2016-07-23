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
    //intList.Show();

    intList.Invert();
    //intList.Show();
    ListIterator<int> li(intList);
    if(li.NotNull())
    {
        cout << *li.First();
        while(li.NextNotNull())
            cout << "->" << *li.Next();
        cout << endl;
    }

//    intList.Delete(15);
//    intList.Show();

//    List<char> charList;
//    charList.Insert('a');
//    charList.Insert('b');
//    charList.Insert('c');
//    charList.Insert('d');
//    charList.Show();
//    charList.Invert();
//    charList.Show();

//    List<char> char2List;
//    char2List.Insert('e');
//    char2List.Insert('f');

//    char2List.Invert();
//    char2List.Show();

//    charList.Concatenate(char2List);
//    charList.Show();

//    std::list<int> listIntegers;
//    listIntegers.push_front(5);
//    listIntegers.push_front(15);
//    listIntegers.push_front(25);
//    listIntegers.push_front(35);

//    std::list<int>::iterator iter = listIntegers.begin();

//    while(iter != listIntegers.end()){
//        cout << *iter << "->";
//        ++iter;
//    }

    return 0;
}
