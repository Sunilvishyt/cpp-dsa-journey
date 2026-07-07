/******************************************************************************
Question : Level order traversal (GFG) 
Description : Given the root of a Binary Tree, your task is to return its Level Order Traversal.
        Note: A level order traversal is a breadth-first search (BFS) of the tree. It visits nodes level by level, starting from the root, and processes all nodes from left to right within each level before moving to the next.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // create answer vector and q to store yet to explore nodes
        vector<int>ans;
        queue<Node*>q;
        
        //push root node address to start exploring
        q.push(root);
        
        //explore untill q is empty
        while(!q.empty()){
            //take 1 node evertime
            Node * temp = q.front();
            q.pop();
            
            //put the node data in ans vector
            ans.push_back(temp->data);
            
            //if left or right nodes are there then push them into queue
            if (temp->left != nullptr){
                q.push(temp->left);
            }
            if (temp->right != nullptr){
                q.push(temp->right);
            }
        }
        return ans;
    }
};
