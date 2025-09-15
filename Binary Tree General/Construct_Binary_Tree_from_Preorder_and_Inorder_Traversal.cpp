// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Brute Force Approach
class Solution {
    int search(vector<int>& inorder, int pivot, int left, int right) {
        for(int i = left; i <= right; i++) {
            if(inorder[i] == pivot)
                return i;
        }
        return -1;
    }
    int k = 0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if(left > right)
            return nullptr;
        int pivot = preorder[k++];
        int pivotIdx = search(inorder, pivot, left, right);
        TreeNode* root = new TreeNode(pivot, solve(preorder, inorder, left, pivotIdx - 1), solve(preorder, inorder, pivotIdx + 1, right));
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = solve(preorder, inorder, 0, inorder.size() - 1);
        return root;
    }
};

// Optimal Approach
class Solution {
    int idx;
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l > r)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        int i = mp[preorder[idx]];
        idx++;
        root -> left = solve(preorder, inorder, l, i - 1);
        root -> right = solve(preorder, inorder, i + 1, r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};