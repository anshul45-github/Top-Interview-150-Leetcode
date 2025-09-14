// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1615950689/

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
    void removeNode(ListNode* temp) {
        ListNode* t = temp -> next;
        temp -> next = temp -> next -> next;
        delete t;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head;
        for(int i = 0; i < n; i++)
            temp1 = temp1 -> next;
        if(!temp1) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        ListNode* temp2 = head;
        while(temp1 -> next) {
            temp2 = temp2 -> next;
            temp1 = temp1 -> next;
        }
        removeNode(temp2);
        return head;
    }
};