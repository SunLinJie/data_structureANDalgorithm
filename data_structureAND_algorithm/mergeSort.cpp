#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void Merge(T *a, T *b, int L, int R, int rightEnd)
{
    int leftEnd = R - 1;
    int tmp = L;
    int NumElements = r4ightEnd - L + 1;

    while(L <= leftEnd && R <= rightEnd){
        if (a[L] <= a[R]) b[tmp++] = a[L++];
        else b[tmp++] = a[R++];
    }
    while(L <= leftEnd)
        b[tmp++] = a[L++];
    while(R <= rightEnd)
        b[tmp++] = a[R++];

    for (int i = 0; i < NumElements; i++, rightEnd--)
        a[rightEnd] = b[rightEnd];
}

template<class T>
void MSort(T *a, T *b, int L, int rightEnd){
    int center;
    if (L < rightEnd){
        center = (L + rightEnd)/2;
        MSort(a, b, L, center);
        MSort(a, b, center+1, rightEnd);
        Merge(a, b, L, center+1, rightEnd);
    }
}

int main()
{
    int a[] = {1, 3, 6, 4, 8, 7, 0, 9, 2, 5};
    int b[11] = {0};

    MSort(a, b, 0, 9);

    for (int i = 0; i < 10; i++)
        cout << b[i] <<endl;



    return 0;
}
