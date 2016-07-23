#include <iostream>

using namespace std;

void BubbleSort(int list[], int n);

int main()
{
    int a[] = {1, 5, 8, 3, 6, 2, 0, 9, 4, 7};
    BubbleSort(a, 10);

    for(int i = 0; i < 10; i++)
        cout << a[i] <<endl;

    return 0;
}

void BubbleSort(int list[], int n)
{

    for (int P = n-1; P > 0; P--)
    {
        bool flag = 0;
        for(int i = 0; i < P; i++)
        {
            if(list[i] > list[i+1]){
                std::swap(list[i], list[i+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

