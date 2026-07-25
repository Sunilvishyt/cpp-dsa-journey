/******************************************************************************
Question : Delete Node in a BST (Leetcode : 450) 
Description : Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
      Basically, the deletion can be divided into two stages:
      Search for a node to remove.
      If the node is found, delete the node.
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;

        if (root->val > key){
            root->left = deleteNode(root->left, key);
            return  root;
        }
        else if (root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }

        // if we reach here its definately the node we have to delete
        else {
            // if its leaf node.
            if (!root->left and !root->right) {
                delete root;
                return NULL;
            }

            // if it has left child
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // if it has right child
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //if its a parent node with both child
            else {
                // find the largest in the left
                TreeNode* child = root->left;
                TreeNode* parent = root;

                //go to the right most (that will be the biggest in the left subtree.
                while (child->right) {
                    parent = child;
                    child = child->right;
                }

                //if parent not equal root means we moved some places
                if (parent != root) {
                    parent->right = child->left;
                    child->right = root->right;
                    child->left = root->left;
                    delete root;
                    return child;
                }
                
                else {
                    child->right = parent->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};
