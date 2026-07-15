/******************************************************************************
Question : Construct Binary Tree from Preorder and Inorder Traversal (Leetcode : 105) 
Description : Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
time complexity : O(n^2)
space complexity : O(n)
*******************************************************************************/

class Solution {
public:

    //function to find the position of element in inorder array
    int find(vector<int>&inorder, int target, int start, int end){
        for (int i = start; i <= end; i++){
            if (inorder[i] == target){
                return i;
            }
        }
        return -1;
    }

    //function to build the whole tree
    TreeNode* build(vector<int>&preorder, vector<int>&inorder, int inStart, int inEnd, int index){
        if (inStart > inEnd) return nullptr;

        TreeNode *root = new TreeNode(preorder[index]);
        int pos = find(inorder, preorder[index], inStart, inEnd);
        
        root->left = build(preorder, inorder, inStart, pos-1,index+1);
        root->right = build(preorder, inorder, pos+1, inEnd, index + (pos - inStart)+1);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = build(preorder, inorder, 0, inorder.size()-1, 0);
        return root;
    }
};
