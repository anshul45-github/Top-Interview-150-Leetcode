// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int maxlen = 0;
        for(int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};