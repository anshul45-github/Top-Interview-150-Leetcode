// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

// Approach-1: Z-function
class Solution {
public:
    void createZarray(string str, int Z[]) {
        Z[0] = 0;
        int l = 0;
        int r = 0;
        for(int i = 1; i < str.size(); i++) {
            if(i > r) {
                l = i;
                r = i;
                while(r < str.size() && str[r] == str[r - l])
                    r++;
                Z[i] = r - l;
                r--;
            }
            else {
                int k1 = i - l;
                if(Z[k1] < r - i + 1)
                    Z[i] = Z[k1];
                else {
                    l = i;
                    r = i;
                    while(r < str.size() && str[r] == str[r - l])
                        r++;
                    Z[i] = r - l;
                    r--;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n = needle.size() + haystack.size() + 1;
        int* Z = new int[n];
        createZarray(needle + "$" + haystack, Z);
        int i = needle.size() + 1;
        while(i < n) {
            if(Z[i] == needle.size())
                return i - needle.size() - 1;
            i++;
        }
        return -1;
    }
};

// Approach-2: Rabin-Karp
#define N 1000000007

class Solution {
public:
    int strStr(string& badi, string& choti) {
        long long hashCode = 0;
        for(int i = 0; i < choti.size(); i++) {
            hashCode *= 31;
            hashCode += choti[i];
            hashCode %= N;
        }
        long long badiHash = 0;
        int m = choti.size();
        long long p_curr = 1;
        for(int i = 0; i < m; i++)
            p_curr = (p_curr * 31) % N;
        for(int i = 0; i < badi.size(); i++) {
            badiHash *= 31;
            badiHash += badi[i];
            badiHash %= N;
            if(i >= m) {
                badiHash -= p_curr * badi[i - m];
                badiHash %= N;
                if(badiHash < 0)
                    badiHash += N;
            }
            if(i >= m - 1) {
                if(badiHash == hashCode) {
                    if(badi.substr(i - m + 1, m) == choti)
                        return i - m + 1;
                }
            }
        }
        return -1;
    }
};