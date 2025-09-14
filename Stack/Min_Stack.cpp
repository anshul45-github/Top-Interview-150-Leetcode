// https://leetcode.com/problems/min-stack/submissions/1770436066/

#include<bits/stdc++.h> 
using namespace std;

// Approach 1: Using Two Stacks
class MinStack {
    stack<long long> s; long long minEle;
public:
    void push(int val) {
        if (s.empty()) { s.push(val); minEle = val; }
        else if (val < minEle) { s.push(2LL*val - minEle); minEle = val; }
        else s.push(val);
    }
    void pop() {
        long long t = s.top(); s.pop();
        if (t < minEle) minEle = 2*minEle - t;
    }
    int top() { return s.top() < minEle ? (int)minEle : (int)s.top(); }
    int getMin() { return (int)minEle; }
};

// Approach 2: Using Single Stack
class MinStack {
    stack<long long> s; long long minEle;
public:
    void push(int val) {
        if (s.empty()) { s.push(val); minEle = val; }
        else if (val < minEle) { s.push(2LL*val - minEle); minEle = val; }
        else s.push(val);
    }
    void pop() {
        long long t = s.top(); s.pop();
        if (t < minEle) minEle = 2*minEle - t;
    }
    int top() { return s.top() < minEle ? (int)minEle : (int)s.top(); }
    int getMin() { return (int)minEle; }
};