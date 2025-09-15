// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    void inorder(TreeNode* root, int k, int& cnt) {
        if(!root)
            return;
        inorder(root -> left, k, cnt);
        cnt++;
        if(cnt == k)
            ans = root -> val;
        inorder(root -> right, k, cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        ans = -1;
        int cnt = 0;
        inorder(root, k, cnt);
        return ans;
    }
};