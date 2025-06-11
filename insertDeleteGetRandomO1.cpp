#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class RandomizedSet
{
public:
    set<int> mySet;
    RandomizedSet() {}

    template <typename T>
    auto select_random(const T &t, size_t n)
    {
        auto it = begin(t);
        advance(it, n);
        return it;
    }

    bool insert(int val)
    {
        bool result;
        if (mySet.find(val) != mySet.end()) // check if the val is already there
        {
            result = false;
        }
        else
        {
            mySet.insert(val);
            result = true;
        }
        return result;
    }

    bool remove(int val)
    {
        bool result = false;
        if (mySet.find(val) != mySet.end())
        {
            mySet.erase(val);
            result = true;
        }
        else
        {
            result = false;
        }
        return result;
    }

    int getRandom()
    {
        if (mySet.size() == 0)
        {
            return 0;
        }
        for (int i = 0; i != mySet.size(); ++i)
        {
            mySet.find(i);
        }
        auto r = rand() % mySet.size();
        auto n = *select_random(mySet, r);
        return n;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
