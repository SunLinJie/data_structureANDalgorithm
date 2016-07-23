#include <iostream>

using namespace std;

template<class T>
void Qsort(T *a, const int left, const int right){
    if (left < right){
        //pivot
        int i = left;
        int j = right+1;   //shaobing
        int pivot = a[left];

        do{
            do i++; while(a[i] < pivot);
            do j--; while(a[j] > pivot);
            if (i < j) std::swap(a[i], a[j]);
        }while(i < j);

        std::swap(a[left], a[j]);

        Qsort(a, left, j-1);
        Qsort(a, j+1, right);
    }
}

int main()
{
    int x[] = {10, 2, 4, 5, 8, 12, 15, 16, 9, 26, 99};

    Qsort(x, 0, 9);

    for (int i = 0; i < 11; i++)
        cout << x[i]  <<endl;

    return 0;
}

