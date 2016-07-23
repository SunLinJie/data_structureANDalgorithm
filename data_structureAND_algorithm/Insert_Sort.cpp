#include <iostream>

using namespace std;

void Insert_sort(int a[], int n);

int main()
{
    int a[] = {1, 9, 2, 8, 4, 5, 0, 6, 7, 3};

    Insert_sort(a, 10);

    for (int i = 0; i < 10; i++)
        cout << a[i] <<endl;

    return 0;
}

void Insert_sort(int a[], int n)
{
    for(int p = 1; p < n; p++){
        int tmp = a[p];
        for (int i = p; i > 0 && a[i-1] > tmp; i--){
            a[i] = a[i-1];
            a[i-1] = tmp;
        }
    }
}
