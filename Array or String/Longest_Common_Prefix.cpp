// https://leetcode.com/problems/longest-common-prefix/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool common(vector<string>& strs, int idx) {
        for(int i = 0; i < strs.size(); i++) {
            if(idx >= strs[i].size() || strs[i][idx] != strs[0][idx])
                return false;
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        while(common(strs, len)) 
            len++;
        return strs[0].substr(0, len);
    }
};