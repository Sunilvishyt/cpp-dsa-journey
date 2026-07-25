//Time Complexity of BST construction = O(n^2)

#include <print>
using namespace std;

// Tree Node structure
struct Node {
    int val;
    Node *left, *right;
    
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

//function to insert particular element in a tree
Node * insert(Node* root, int target){
    if (!root){
        return new Node(target);
    }
    
    if (root->val > target){
         root->left = insert(root->left, target);
    }
    else {
        root->right = insert(root->right, target);
    }
    
    return root;
}

//to later traverse via inorder (A BST inorder traversal always results in sorted)
void traverse(Node* root){
    if (!root) return;
    
    traverse(root->left);
    print(" {} ",root->val);
    traverse(root->right);
    
}

int main()
{
    int arr[] = {4,2,3,7,1,9,0};
    Node * root = NULL;
    //pick each target and insert it in the correct location with the insert function
    for (int i = 0; i < 7; i++){
        root = insert(root, arr[i]);
    }

  
    traverse(root); //output -> 0 1 2 3 4 7 9 
    
    return 0;
}
