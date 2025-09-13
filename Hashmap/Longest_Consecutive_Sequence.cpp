// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach (TLE)
class Solution {
private: 
    bool longestConsecutive(vector<int>& nums, int target){
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longestConsecutiveSequence = 0;
        for(auto num : nums){
            int currentNumber = num;
            int currentConsecutiveSequence = 1;
            while(longestConsecutive(nums, currentNumber+1)){
                currentNumber += 1;
                currentConsecutiveSequence += 1;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
        }
        return longestConsecutiveSequence;
    }
};

// Optimal Approach: Using Sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int currentConsecutiveSequence = 1;
        int longestConsecutiveSequence = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currentConsecutiveSequence++;
                }
                else{
                    longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                    currentConsecutiveSequence = 1;
                }
            }
        }
        return max(longestConsecutiveSequence, currentConsecutiveSequence);
    }
};

// Most Optimal Approach: Using Hashmap (TLE idk why)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        
        for (auto i : nums) {
            mp[i] = true;
        }
        
        for (auto i : nums) {
            if (mp.find(i - 1) != mp.end()) {
                mp[i] = false;
            }
        }
        
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]]) {
                int j = 0;
                
                while(mp.count(nums[i]+j) > 0){
                    j++;
                }
                
                count = max(count, j);
            }
        }
        
        return count;
    }
};

// Most Optimal Approach: Using Hashset
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int longestConsecutiveSequence = 0;
        for(int num : set){
            if(set.find(num-1) == set.end()){
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while(set.find(currentNumber+1) != set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};