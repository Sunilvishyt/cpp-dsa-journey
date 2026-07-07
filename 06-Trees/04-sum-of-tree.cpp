/******************************************************************************
Question : Sum of Binary Tree (GFG) 
Description : Given a binary tree, find the sum of values of all the nodes. 
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
int Sum(Node* root, int &sum) {
	if (root == nullptr) {
		return 0;
	}
	
	return root->data + Sum(root->left, sum) + Sum(root->right, sum);
}

class Solution {
	public:
	int sumBT(Node* root) {
		// code here
		int sum = 0;
		return Sum(root, sum);
		
	}
};
