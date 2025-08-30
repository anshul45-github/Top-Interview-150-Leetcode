// https://leetcode.com/problems/jump-game-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        int maxReach = 0;
        int jumps = 0;
        int near = 0;
        for(int i = 0; i < nums.size();) {
            while(i <= near) {
                int reach = min(i + nums[i], (int)nums.size() - 1);
                maxReach = max(maxReach, reach);
                i++;
            }
            jumps++;
            near = maxReach;
        }
        return jumps - 1;
    }
};