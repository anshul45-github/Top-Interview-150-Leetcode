// https://leetcode.com/problems/zigzag-conversion/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows || numRows == 1)
            return s;
        string ans = "";
        for(int i = 1; i <= numRows; i++) {
            int k = i - 1;
            if(i == 1 || i == numRows) {
                while(k < s.size()) {
                    ans += s[k];
                    k += 2 * numRows - 2;
                }
            }
            else {
                while(k < s.size()) {
                    ans += s[k];
                    k += 2 * (numRows - i);
                    if(k < s.size())
                        ans += s[k];
                    k += 2 * (i - 1);
                }
            }
        }
        return ans;
    }
};