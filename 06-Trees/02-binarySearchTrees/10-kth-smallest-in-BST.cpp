/******************************************************************************
Question : Kth Smallest Element in a BST (Leetcode : 230) 
Description : Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void find(TreeNode *root, int k, int &index, int &ans){
        if (!root) return;
        if (ans != -1) return;

        find(root->left, k, index, ans);
        index += 1;
        if (index == k){
            ans = root->val;
        }
        find(root->right, k, index, ans);

        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        int ans = -1;

        find(root, k, index, ans);
        return ans;
    }
};
