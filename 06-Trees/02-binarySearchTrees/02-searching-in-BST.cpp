//Time Complexity = O(n) 
//its better than binary tree 


bool Search(Node *root, int target) {
	if (!root) return false;
	if (root->val == target) return true;
	if ( root->val > target) return Search(root->left, target);
	else {
		return Search(root->right, target);
	}
}

