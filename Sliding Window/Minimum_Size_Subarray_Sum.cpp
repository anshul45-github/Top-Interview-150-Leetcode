// https://leetcode.com/problems/minimum-size-subarray-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while(sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if(sum >= target)
                minLen = min(minLen, right - left + 1);
        }
        if(minLen == INT_MAX)
            return 0;
        return minLen;
    }
};