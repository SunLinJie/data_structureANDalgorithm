#include <iostream>
#include "MyStack.h"
#include <string>

using namespace std;

class Dog
{

};

int main()
{
    MyStack<int> st;
    MyStack<Dog> dogStack;
    MyStack<string> str;

    st.Push(99);
    st.Push(22);
    st.Push(18);
    st.Push(67);
    cout << st.Top() <<endl;
    st.Pop();
    cout << st.Top() <<endl;
    st.Pop();
    cout << st.Top() <<endl;
}
