/******************************************************************************
Question : Left View of Binary Tree (GFG) 
Description : Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
      Note: If the tree is empty, return an empty list.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	vector<int> leftView(Node *root) {
		vector<int>ans;
		if (!root)  //if root is empty return empty array.
			return ans;
		
		queue<Node*>q;
		q.push(root);
		
		while (!q.empty()) {
		    //count the q size to know the number of elements in a particular level
			int n = q.size();
			ans.push_back(q.front()->data);  //push first one
			
			//remove all the elements of particular level
			while (n--) {
			    Node *temp = q.front();
				q.pop();
				if (temp->left)
					q.push(temp->left);
					
				if (temp->right)
					q.push(temp->right);
			}
		}
		return ans;
	}
};
