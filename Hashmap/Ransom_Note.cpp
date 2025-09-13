// https://leetcode.com/problems/ransom-note

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Hashmap
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(int i = 0; i < magazine.size(); i++)
            mp[magazine[i]]++;
        for(int i = 0; i < ransomNote.size(); i++) {
            if(mp[ransomNote[i]] == 0)
                return false;
            mp[ransomNote[i]]--;
        }
        return true;
      }
};

// Approach 2: Using Hashset and count function
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        unordered_set<char> ransomSet(ransomNote.begin(), ransomNote.end());

        for (char c : ransomSet) {
            if (countOccurrences(magazine, c) < countOccurrences(ransomNote, c)) {
                return false;
            }
        }
        return true;
    }

private:
    int countOccurrences(const string& str, char c) {
        return count(str.begin(), str.end(), c);
    }    
};