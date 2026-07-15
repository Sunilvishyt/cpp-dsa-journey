/******************************************************************************
Question : Binary Tree Zigzag Level Order Traversal (Leetcode : 103) 
Description : Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root){
            return ans;
        }
        queue<TreeNode*>treeNodesQueue;
        bool leftToRight = true; //flag variable
        treeNodesQueue.push(root);

        while(!treeNodesQueue.empty()){
            int queueSize = treeNodesQueue.size();
            vector<int>elements(queueSize);

            for(int i = 0; i < queueSize; i++){
                TreeNode *node = treeNodesQueue.front();
                treeNodesQueue.pop();
                
                //if we have to store left to right then fill the array from start to end otherwise end to start
                int index = leftToRight ? i : (queueSize - 1 - i);
                elements[index] = node->val;

                if (node->left) treeNodesQueue.push(node->left);
                if (node->right) treeNodesQueue.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(elements);
        }

    return ans;
    }
};
