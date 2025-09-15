// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/1745860150/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* head = root; // start of current level
        while (head) {
            Node* dummy = new Node(0); // dummy node to track next level
            Node* temp = dummy;        // pointer to build next level connections
            
            // iterate over current level
            for (Node* curr = head; curr != nullptr; curr = curr->next) {
                if (curr->left) {
                    temp->next = curr->left;
                    temp = temp->next;
                }
                if (curr->right) {
                    temp->next = curr->right;
                    temp = temp->next;
                }
            }
            
            // move head to start of next level
            head = dummy->next;
            delete dummy; // free dummy node
        }
        
        return root;
    }
};