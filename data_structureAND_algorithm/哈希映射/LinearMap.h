#ifndef LINEARMAP_H
#define LINEARMAP_H

#include <vector>

template <class Key, class Value>
class LinearMap
{
public:
    LinearMap(int size = 101):arr(size)
    {
        currentsize = 0;
    }

    void Put(const Key & k, const Value & v)
    {
        arr[currentsize] = DataEntry(k, v);
        ++currentsize;
    }

    void Get(const Key & k)
    {
        //linear find
        for(size_t i  = 0; i < currentsize; i++)
        {
            if(arr[i].key == k)
                return arr[i].value;
        }
        return Value();
    }

private:
    struct DataEntry{
        Key key;
        Value value;

        DataEntry(const Key & k = Key(), const Value & v = Value()):key(k), value(v){}
    };

    std::vector<DataEntry> arr;
    int currentsize;
};

#endif // LINEARMAP_H
