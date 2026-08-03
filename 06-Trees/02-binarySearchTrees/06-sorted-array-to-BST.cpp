/******************************************************************************
Question : Convert Sorted Array to Binary Search Tree (Leetcode : 108) 
Description : Given an integer array nums where the elements are sorted in ascending order, convert it to a binary search tree.
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
    TreeNode * create( int start, int end, vector<int>nums){
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = create(start, mid-1,nums );
        temp->right = create(mid+1,end, nums);
        return temp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* tree = nullptr;

        tree = create( 0, nums.size()-1, nums);

        return tree;
    }
};
