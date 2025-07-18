// https://leetcode.com/problems/summary-ranges/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        vector<string> ans;
        int start = 0;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[start] + cnt)
                cnt++;
            else {
                if(cnt == 1)
                    ans.push_back(to_string(nums[start]));
                else
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[start + cnt - 1]));
                start = i;
                cnt = 1;
            }
        }
        if(cnt == 1)
            ans.push_back(to_string(nums[start]));
        else
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[start + cnt - 1]));
        return ans;
    }
};