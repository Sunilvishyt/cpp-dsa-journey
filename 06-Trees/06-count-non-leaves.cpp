/******************************************************************************
Question : Count Non-Leaf Nodes in Tree (GFG) 
Description : Given a Binary Tree of size n, your task is to return the count of all the non-leaf nodes of the given binary tree..
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/


/*Structure of the node of the tree is as
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes

class Solution {
	public:
	void Counter(Node *root, int &count) {
		if (root == nullptr){
		    return;
		}
		
		//use or operator because one node can have single children
		if (root->left != nullptr || root->right != nullptr) count++;
		
		Counter(root->left, count);
		Counter(root->right, count);
	}
	
	int countNonLeafNodes(Node* root) {
		// Code here
		int count = 0;
		Counter(root, count);
		return count; 
		
	}
};
