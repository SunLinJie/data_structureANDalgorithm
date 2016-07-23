#include <iostream>

using namespace std;

int SequentialSearch(int *a, const int n, const int x);

int main()
{
    int a[] = {1, 4, 6, 7, 9};

    int m = SequentialSearch(a, 5, 7);

    if (m == -1)
        cout << "not find!" <<endl;
    else
        cout <<"a[" << m << "]" <<endl;

    return 0;
}

int SequentialSearch(int *a, const int n, const int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    if (i == n)
        return -1;
}
