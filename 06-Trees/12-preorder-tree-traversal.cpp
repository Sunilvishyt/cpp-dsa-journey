//Preorder tree traversal with recursion and iterative

//iterative
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        stack<Node *>st;
        vector<int>ans;
        st.push(root);
        
        while(!st.empty()){
            Node *temp = st.top();
            st.pop();
            
            ans.push_back(temp->data);
            
            if (temp->right) {
                st.push(temp->right);
            }
            if (temp->left){
                st.push(temp->left);
            }
        }
        return ans;
    }
};



//recursive solution 
  public:
    void traverse(Node*root, vector<int>&ans){
        if (root == NULL) return;
        
        ans.push_back(root->data);
        traverse(root->left,ans);
        traverse(root->right,ans);
    }
    
    vector<int> preOrder(Node* root) {
        vector<int>ans;
        traverse(root, ans);
        return ans;
    }
};
