// https://leetcode.com/problems/simplify-path/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while(i < path.size() && path[i] == '/')
            i++;
        while(i < path.size()) {
            int start = i;
            while(i < path.size() && path[i] != '/')
                i++;
            string folder = path.substr(start, i - start);
            if(folder == "..") { 
                if(!st.empty())
                    st.pop();
            }
            else if(folder == ".") {}
            else
                st.push(folder);
            while(i < path.size() && path[i] == '/')
                i++;
        }
        string ans = "";
        while(!st.empty()) {
            string top = st.top();
            st.pop();
            reverse(top.begin(), top.end());
            ans += top + "/";
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0)
            return "/";
        return ans;
    }
};