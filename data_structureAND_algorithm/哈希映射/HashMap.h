#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>

template <class Key, class Value>
class HashMap
{
public:
    HashMap(int size = 101):arr(size)
    {
        currentsize = 0;
    }

    void Put(const Key & k, const Value & v)
    {
        int pos = myhash(k);
        arr[pos] = DataEntry(k, v);
        ++currentsize;
    }

    Value Get(const Key & k)
    {
        int pos = myhash(k);
        if(arr[pos].key == k)
            return  arr[pos].value;
        else
            return Value();
    }

    unsigned hash(const Key & k) const
    {
        unsigned int hashVal = 0;
        const char *keyp = reinterpret_cast<const char *>(&k);
        for (size_t i = 0; i < sizeof(Key); i++)
            hashVal = 37 * hashVal + keyp[i];
        return hashVal;
    }

    int myhash(const Key & k) const
    {
        unsigned hashVal = hash(k);
        hashVal %= arr.size();
        return hashVal;
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

#endif // HASHMAP_H
