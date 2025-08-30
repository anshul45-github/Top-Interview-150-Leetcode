// https://leetcode.com/problems/h-index/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int maxi = 0;
        for(int i = citations.size() - 1; i >= 0; i--) {
            if(citations[i] >= citations.size() - i)
                maxi++;
            else
                break;
        }
        return maxi;
    }
};