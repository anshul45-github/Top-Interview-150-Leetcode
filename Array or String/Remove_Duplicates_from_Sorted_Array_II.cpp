// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        for(int i = 0; i < nums.size();) {
            int x = nums[i];
            int cnt = 0;
            while(i < nums.size() && nums[i] == x) {
                cnt++;
                i++;
            }
            for(int j = 0; j < min(cnt, 2); j++, start++)
                nums[start] = x;
        }
        return start;
    }
};