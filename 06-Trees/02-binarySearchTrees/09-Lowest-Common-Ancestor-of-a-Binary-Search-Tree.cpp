/******************************************************************************
Question : Lowest Common Ancestor of a Binary Search Tree (Leetcode : 235) 
Description : Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
      According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        //if both p and q are less than root value - go to left
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        //if both p and q are larger than root value - go to right
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right,p,q);

        // if the p and q are going to different direction that is the point we have to return.
        else {
            return root;
        }
    }
};
