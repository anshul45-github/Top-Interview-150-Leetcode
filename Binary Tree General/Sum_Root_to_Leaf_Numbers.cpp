// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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

class Solution {
    int ans;
    void solve(TreeNode* root, int curr) {
        if(!root)
            return;
        if(root -> left == nullptr && root -> right == nullptr) {
            ans += curr * 10 + root -> val;
            return;
        }
        curr = curr * 10 + root -> val;
        solve(root -> left, curr);
        solve(root -> right, curr);
    }
public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
        solve(root, 0);
        return ans;
    }
};