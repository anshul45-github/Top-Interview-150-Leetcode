// https://leetcode.com/problems/contains-duplicate-ii/description/

#include<bits/stdc++.h> 
using namespace std;

// Using Hashmap
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (seen.find(val) != seen.end() && i - seen[val] <= k) {
                return true;
            }
            seen[val] = i;
        }

        return false;        
    }
};

// Using Hashset
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                seen.erase(nums[i - k - 1]);
            }

            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }

            seen.insert(nums[i]);
        }

        return false;        
    }
};