// https://leetcode.com/problems/candy/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());
        candies[0] = 1;
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
            else
                candies[i] = 1;
        }
        vector<int> candiesr(ratings.size());
        candiesr.back() = 1;
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1])
                candiesr[i] = candiesr[i + 1] + 1;
            else
                candiesr[i] = 1;
        }
        int ans = 0;
        for(int i = 0; i < ratings.size(); i++)
            ans += max(candies[i], candiesr[i]);
        return ans;
    }
};