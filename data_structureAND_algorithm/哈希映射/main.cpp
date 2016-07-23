#include <iostream>
#include <map>   // binary tree mapping ,RedBlackTree
#include <string>
//#include "LinearMap.h"
#include "HashMap.h"

//#include <hash_map>

using namespace std;

int main()
{
//    map<string, int> m;
//    m["Bill"] = 98;
//    m["Tom"] = 87;
//    m["Mary"] = 100;

//    cout << m["Tom"] <<endl;
//    LinearMap<string, int> lm;
//    lm.Put("Bill", 99);
//    lm.Put("Tom", 98);

//    std::cout << "LinearMap: " << lm.Get("Tom")<< endl;

//    hash_map<string, int> Hm;
//    Hm["Bill"] = 90;
//    Hm["Tom"] = 99;

//    cout << Hm["Tom"] << endl;


    HashMap<string, int> hm;
    hm.Put("Bill", 99);
    hm.Put("Tom", 90);
    cout << hm.Get("Bill") << endl;
    cout << hm.Get("Tom") << endl;
    cout << hm.hash("Bill") << endl;
    cout << hm.myhash("Bill") << endl;

    return 0;
}
