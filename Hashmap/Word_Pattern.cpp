// https://leetcode.com/problems/word-pattern/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> strmp;
        int j = 0;
        for(int i = 0; i < pattern.size(); i++) {
            string temp = "";
            if(j >= s.size())
                return false;
            while(j < s.size() && s[j] != ' ')  {
                temp += s[j];
                j++;
            }
            j++;
            if(!mp.count(pattern[i])) {
                if(strmp.find(temp) != strmp.end())
                    return false;
                strmp.insert(temp);
                mp[pattern[i]] = temp;
            }
            else if(mp[pattern[i]] != temp)
                return false;
        }
        if(j < s.size())
            return false;
        return true;
    }
};