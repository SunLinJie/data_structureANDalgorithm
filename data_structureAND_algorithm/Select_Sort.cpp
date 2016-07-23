#include <iostream>

using namespace std;

void Select_sort(int a[], int n);

int main()
{
    int a[] = {1, 9, 2, 8, 4, 5, 0, 6, 7, 3};
    Select_sort(a, 10);

    for (int i = 0; i < 10; i++)
        cout << a[i] << endl;

    return 0;
}

void Select_sort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)  //i < n or n-1
    {
        int min = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[min])
                min = j;
        }
        std::swap(a[i], a[min]);
    }
}
