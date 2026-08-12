/******************************************************************************
Question : Convert Sorted List to Binary Search Tree (Leetcode : 109) 
Description : Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode * convert(vector<int>&arr, int start, int end){
        if (start > end) return nullptr;

        int mid = (start + end) / 2;

        TreeNode * node = new TreeNode(arr[mid]);

        node->left = convert(arr, start, mid-1);
        node->right = convert(arr, mid+1, end);

        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;

        while (temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        return convert(arr,0, arr.size()-1);

    }
};
