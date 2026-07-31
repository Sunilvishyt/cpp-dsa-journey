/******************************************************************************
Question : Minimum Distance Between BST Nodes (Leetcode : 783) 
Description : Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
time complexity : O(n)
space complexity : O(1)
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
    void minDiff(TreeNode* root, int &prev, int &ans){
        if (!root) return;

        minDiff(root->left, prev, ans);
      
        if (prev != INT_MIN) 
            ans = min(ans, root->val - prev);
        prev = root->val;
      
        minDiff(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;
        minDiff(root, prev, ans);
        return ans;
    }
};

//we use inorder traversal to get to nodes because it traverses the node in acsending order in BST, this way we can find the minimum difference by comparing the difference between nodes,
//thus, this has the best chances to find minimum difference and not compare everynode with everybody else. 
