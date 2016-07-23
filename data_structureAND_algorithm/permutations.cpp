#include <iostream>

using namespace std;

void Perm(char *p, const int start, const int end)
{
    if(start == end)
    {
        for (int i = 0; i <=end; i++)
            cout << p[i];
        cout <<endl;
    }
    else
        for(int i = start; i <=end; i++)
        {
            std::swap(p[start], p[i]);
            Perm(p, start+1, end);
            std::swap(p[start], p[i]);
        }

//    //start a
//    std::swap(p[0], p[0]);
//    Perm(p, 1, 2);
//    std::swap(p[0], p[0]);
//    //start b
//    std::swap(p[0], p[1]);
//    Perm(p, 1, 2);
//    std::swap(p[0], p[1]);
//    //start c
//    std::swap(p[0], p[2]);
//    Perm(p, 1, 2);
//    std::swap(p[0], p[2]);
}

int main()
{
    char s[] = "abc";

    Perm(s, 0, 2);

    return 0;
}
