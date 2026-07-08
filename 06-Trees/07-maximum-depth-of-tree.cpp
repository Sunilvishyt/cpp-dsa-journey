/******************************************************************************
Question : Height of Binary Tree (GFG) 
Description : Given the root of a binary tree, your task is to find the maximum depth of the tree.
        Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node..
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
	
	int heightFinder(Node* root) {
		if (root == nullptr)
			return 0;
		
		return 1 + max(heightFinder(root->left), heightFinder(root->right));
		
	}
	
	int height(Node* root) {
		// code here
		int left = heightFinder(root->left);
		int right = heightFinder(root->right);
		return max(left, right);

	}
};
