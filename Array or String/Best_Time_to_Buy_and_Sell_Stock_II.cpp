// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int n = prices.size();
        int maxProfit = 0;
        for(int i = 1; i < n; i++) {
            minVal = min(minVal, prices[i]);
            maxProfit += prices[i] - minVal;
            if(prices[i] - minVal > 0)
                minVal = prices[i];
        }
        return maxProfit;
    }
};