/******************************************************************************
Question : Count Leaves in Binary Tree (GFG) 
Description : Given a Binary Tree of size n, You have to count leaves in it.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    
    void countAll(Node *root, int &count){
        if (root == nullptr){
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr){
            count++;
        }
        
        countAll(root->left, count);
        countAll(root->right, count);
    }
    
    int countLeaves(Node* root) {
        // write code here
        int count = 0;
        countAll(root, count);
        
        return count;
    }
};
