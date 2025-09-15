// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    int k;
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int left, int right) {
        if(left > right)
            return nullptr;
        int pivot = postorder[k--];
        int pivotIdx = search(inorder, pivot, left, right);
        TreeNode* root = new TreeNode(pivot);
        TreeNode* r = solve(postorder, inorder, pivotIdx + 1, right);
        TreeNode* l = solve(postorder, inorder, left, pivotIdx - 1);
        root -> right = r;
        root -> left = l;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        k = postorder.size() - 1;
        TreeNode* root = solve(postorder, inorder, 0, inorder.size() - 1);
        return root;
    }
};

// Optimal Approach
class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int n = inorder.size(), postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }

    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = mp[root -> val];
        root -> right = build(in, post, inIdx+1, inEnd, postIdx);
        root -> left  = build(in, post, inStart, inIdx-1, postIdx);
        return root;
    }
};