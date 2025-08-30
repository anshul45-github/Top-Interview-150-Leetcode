// https://leetcode.com/problems/insert-delete-getrandom-o1

#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        bool x = !s.count(val);
        s.insert(val);
        return x;
    }
    
    bool remove(int val) {
        bool x = s.count(val);
        s.erase(val);
        return x;
    }
    
    int getRandom() {
        int i = rand() % s.size();
        auto it = s.begin();
        advance(it, i);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */