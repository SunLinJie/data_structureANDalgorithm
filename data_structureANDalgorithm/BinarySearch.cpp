#include <iostream>

using namespace std;

int BinarySearch(int *a, const int x, const int n);

int BinarySearch_R(int *a, const int x, const int left, const int right);

long jiechen(int n);
long jiechen2(int n);

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int position;

    //position = BinarySearch(a, 7, 10);
    position = BinarySearch_R(a, 7, 0, 9);
    if (position < 0)
        cout << "not find!"<<endl;
    else
        cout << "find it!" <<endl;

    cout << jiechen(5)<<endl;

    cout << jiechen2(5) <<endl;

    return 0;
}

int BinarySearch(int *a, const int x, const int n)
{
    int left, right, mid;
    left = 0;
    right = n-1;

    while(left <= right){
        mid = (left + right)/2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            left = mid + 1;
        else if (a[mid] > x)
            right = mid -1;
    }
    return -1;
}

long jiechen(int n)
{
    if ( n == 0) return 1;
    else return n * jiechen(n - 1);
}

long jiechen2(int n)
{
    long result = 1;
    for(int i = n; i > 0; i--)
        result = result * i;
    return result;
}

int BinarySearch_R(int *a, const int x, const int left, const int right)
{
    if (left <= right){
        int mid = (left + right)/2;
        if (a[mid] < x) return BinarySearch_R(a, x, mid + 1, right);
        else if (a[mid] > x) return BinarySearch_R(a, x, left, mid -1);

        return mid;
    }
    return -1;
}
