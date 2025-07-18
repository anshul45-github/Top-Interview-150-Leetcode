// https://leetcode.com/problems/remove-element/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size() - 1;
        for(int i = 0; i <= last;) {
            if(nums[i] == val) {
                swap(nums[i], nums[last]);
                last--;
            }
            else
                i++;
        }
        return last + 1;
    }
};