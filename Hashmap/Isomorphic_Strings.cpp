// https://leetcode.com/problems/isomorphic-strings

#include<bits/stdc++.h>
using namespace std;

// Solution 1: Two Hashmaps
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, bool> mp2;
        for(int i = 0; i < s.size(); i++) {
            if(mp1.find(s[i]) == mp1.end()) {
                mp1[s[i]] = t[i];
                if(mp2[t[i]])
                    return false;
                mp2[t[i]] = true;
            }
            else if(mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i])
                return false;
        }
        return true;
    }
};

// Solution 2: Single Hashmap
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMap;

        for (int i = 0; i < s.length(); ++i) {
            char sc = s[i];
            char tc = t[i];

            if (charMap.count(sc)) {
                if (charMap[sc] != tc) {
                    return false;
                }
            } else {
                for (auto& pair : charMap) {
                    if (pair.second == tc) {
                        return false;
                    }
                }
                charMap[sc] = tc;
            }
        }

        return true;        
    }
};