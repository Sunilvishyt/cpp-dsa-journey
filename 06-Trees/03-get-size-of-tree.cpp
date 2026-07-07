/******************************************************************************
Question : Size of Binary Tree (GFG) 
Description : Given the root of a binary tree, return the size of the tree. The size of a binary tree is the total number of nodes in the tree.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//helper function for recursion
void Traverse(Node *root, int &count){
    if (!root){
        return ;
    }
    
    count+=1;
    Traverse(root->left, count);
    Traverse(root->right, count);
}

class Solution {
  public:
    int getSize(Node* root) {
      //count variable will be passed by reference.
        int count = 0;

        Traverse(root, count);

        return count;
    }
};
