// https://leetcode.com/problems/group-anagrams/description/

#include<bits/stdc++.h>
using namespace std;

// Solution 1: Using Hashmap
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        int idx = 0;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++) {
            string x = strs[i];
            sort(x.begin(), x.end());
            if(!mp.count(x)) {
                mp[x] = idx;
                idx++;
                vector<string> temp = {strs[i]};
                ans.push_back(temp);
            }
            else 
                ans[mp[x]].push_back(strs[i]);
        }
        return ans;
    }
};

// Solution 2: Using Hashmap and Frequency Count
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (string& s : strs) {
            vector<int> count(26, 0);

            // Count frequency of each letter in the string
            for (char c : s) {
                count[c - 'a']++;
            }

            string key = "";
            for (int num : count) {
                key += to_string(num) + "#";
            }

            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : ans) {
            result.push_back(entry.second);
        }

        return result;        
    }
};