#include <iostream>

using namespace std;

//void swap(int *x, int *y);

//#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

//void swap(int &x, int &y);

int main()
{
    int a, b, t;
    a = 1;
    b = 10;

    cout << "a = " << a << "," <<"b = " << b << endl;

    //swap(&a, &b);

    //SWAP(a, b, t);
    //swap(a, b);

    std::swap(a, b);

    cout << "a = " << a << "," << "b = " << b << endl;

    return 0;
}


//pointer
/*
void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}
*/

/*
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
*/
