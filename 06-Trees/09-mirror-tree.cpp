/******************************************************************************
Question : Mirror Tree (GFG) 
Description : Given the root of a binary tree, convert the binary tree to its Mirror tree.
      Note: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirrorTree(Node *root){
        if (root == NULL) return;
        if (root->left == NULL and root->right == NULL) return;
        
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        
    }
    
    void mirror(Node* root) {
        // code here
        mirrorTree(root);
    }
};
