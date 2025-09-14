// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/1745434359/

#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> s;
        ListNode* temp = head;
        while(temp) {
            s[temp -> val]++;
            temp = temp -> next;
        }
        temp = head;
        ListNode* prev = nullptr;
        for(auto x : s) {
            if(x.second > 1)
                continue;
            temp -> val = x.first;
            prev = temp;
            temp = temp -> next;
        }
        if(prev == nullptr)
            return prev;
        prev -> next = nullptr;
        return head;
    }
};