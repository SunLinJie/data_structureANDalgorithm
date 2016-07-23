#include <iostream>
#include <list>

using namespace std;

void PrintListContents(const list<int>& listInput);

int main()
{
    list<int> a, b;
    std::list<int>::iterator iter;

    b.push_front(10);
    b.push_front(20);

    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    a.push_back(5);

    PrintListContents(a);

    iter = a.begin();
    ++iter;

    a.insert(iter, 10);
    a.insert(a.end(), 1, 20);

    a.insert(a.begin(), b.begin(), b.end());
    PrintListContents(a);

    a.reverse();
    PrintListContents(a);

    a.sort();
    PrintListContents(a);
    return 0;
}

void PrintListContents(const list<int>& listInput)
{
    cout <<endl;
    cout << "{";
    std::list<int>::const_iterator iter;
    for(iter = listInput.begin(); iter != listInput.end(); ++iter)
    {
        cout << *iter <<" ";
    }

    cout << "}" << endl;
}
