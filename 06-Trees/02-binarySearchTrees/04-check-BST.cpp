/******************************************************************************
Question : Validate Binary Search Tree (Leetcode : 98) 
Description : Given the root of a binary tree, determine if it is a valid binary search tree (BST).
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
    //inorder traversal of valid BST always returns in a valid bst.
    void inorderTraverse(TreeNode*root, vector<int>&ans){
        if (!root) return;
        inorderTraverse(root->left, ans);
        ans.push_back(root->val);
        inorderTraverse(root->right, ans);
    }


    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorderTraverse(root, ans);

        //if there is only one element then its a valid bst.
        if (ans.size() == 1) return true;

        //traverse the ans array and check if its in strict ascending order or not
        for (int i = 1; i < ans.size(); i++){
            if (ans[i] <= ans[i-1]) return false;
        }
        return true;


//----------------optimal-solution without using extra space-----------------------------------
class Solution {
public:

    bool checkBST(TreeNode*root, TreeNode* &prev){
        if (!root) return true;

        bool left = checkBST(root->left, prev);
        if (left == false) return false;

        if (prev != nullptr && root->val <= prev->val) 
            return false;

        prev = root;

        bool right = checkBST(root->right, prev);
        if (right == false) return false;

        //if code reaches here then, left = right = true;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        return checkBST(root, prev);

    }
};
    }
};
