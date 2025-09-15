// https://leetcode.com/problems/symmetric-tree

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative approach
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root -> left);
        q.push_back(root -> right);
        while(!q.empty()) {
            if(!q.front() && !q.back()) {
                q.pop_front();
                q.pop_back();
                continue;
            }
            if(!q.front() || !q.back())
                return false;
            if(q.front() -> val != q.back() -> val)
                return false;
            TreeNode* front = q.front();
            TreeNode* back = q.back();
            q.pop_front();
            q.pop_back();
            q.push_front(front -> left);
            q.push_back(back -> right);
            q.push_front(front -> right);
            q.push_back(back -> left);
        }
        return true;
    }
};

// Recursive approach
class Solution {
    bool solve(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr ^ right == nullptr)
            return false;
        return solve(left -> left, right -> right) && solve(left -> right, right -> left) && right -> val == left -> val;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root -> left, root -> right);
    }
};