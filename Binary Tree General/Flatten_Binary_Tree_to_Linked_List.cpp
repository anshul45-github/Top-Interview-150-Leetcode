// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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

// Extra Space Approach
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> nodes;
        preorder(root, nodes);
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
    }

    void preorder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (!node) return;
        nodes.push_back(node);
        preorder(node->left, nodes);
        preorder(node->right, nodes);
    }
};

// Optimal Approach
class Solution {
    TreeNode* pred(TreeNode* root) {
        while(root -> right)
            root = root -> right;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        while(temp) {
            if(temp -> left) {
                TreeNode* pre = pred(temp -> left);
                pre -> right = temp -> right;
                temp -> right = temp -> left;
                temp -> left = nullptr;
            }
            temp = temp -> right;
        }
        return;
    }
};