// https://leetcode.com/problems/basic-calculator/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<bool> st;
        int invert = 0;
        for(int i = 0; i < s.size(); ) {
            if(s[i] == ' ') { 
                i++;
                continue;
            }
            if(s[i] == ')') {
                bool t = st.top();
                st.pop();
                if(t)
                    invert--;
                i++;
                continue;
            }
            bool isNegative = false;
            if(s[i] == '-') {
                isNegative = true;
                i++;
            }
            else if(s[i] == '+')
                i++;
            while(i < s.size() && s[i] == ' ')
                i++;
            if(s[i] == '(') {
                if(isNegative) {
                    invert++;
                    st.push(1);
                }
                else    
                    st.push(0);
                i++;
                continue;
            }
            while(i < s.size() && s[i] == ' ')
                i++;
            int currNum = 0;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                currNum = currNum * 10 + (s[i] - '0');
                i++;
            }
            if((isNegative + invert) & 1)
                currNum = -currNum;
            res += currNum;
        }
        return res;
    }
};