// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/1769761771/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[1] != b[1])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int currEnd = points[0][1], ans = 1;
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > currEnd) {
                ans++;
                currEnd = points[i][1];
            }
        }
        return ans;
    }
};