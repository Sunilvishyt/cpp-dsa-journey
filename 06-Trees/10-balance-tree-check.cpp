/******************************************************************************
Question : Balanced Tree Check (GFG) 
Description : Given the root of a binary tree, determine if it is height-balanced or not.
    Note: A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.
    
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/



/*
Definition for Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	int height(Node *root, bool &valid) {
	    //only go further if the tree is not proved to be invalid
		if (valid) {
		    
			if (!root)
				return 0;
			
			int left = height(root->left, valid);
			int right = height(root->right, valid);
			
			if (abs(left - right) > 1)
				valid = false;
			
			return 1 + max(left, right);
		}
		
		return - 1;
	}
	
	bool isBalanced(Node* root) {
		// create valid var to track if the tree is valid
		bool valid = true;
		
		height(root, valid);
		
		return valid;
	}
};
