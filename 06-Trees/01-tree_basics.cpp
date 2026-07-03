#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

void TraverseTreePreorder(Node *node) {
	if (node==NULL) {
		return;
	}

	cout << node->data <<endl;
	TraverseTreePreorder(node->left);
	TraverseTreePreorder(node->right);
}

void LevelTreeTraverse(Node *node){
    queue<Node*>q;
    q.push(node);
    
    while (!q.empty()){
        Node * temp = q.front();
        q.pop();
        cout << temp->data << endl;
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL) 
            q.push(temp->right);
    }
}

int main()
{
	int x;
	queue<Node*>q;
	cout << "Enter the root node : ";
	cin >> x;
	Node *root = new Node(x);

	q.push(root);

	while (!q.empty()) {
		Node *temp = q.front(); 
		q.pop();

		cout << "Enter the left child of " << temp->data << " : ";
		cin >> x;
		if (x != -1) {
			temp -> left = new Node(x);
			q.push(temp->left);
		}

		cout << "Enter the right child of " << temp->data << " : ";
		cin >> x;

		if (x != -1) {
			temp->right = new Node(x);
			q.push(temp->right);
		}
	}

    cout << endl;
    cout << "Level by Level tree traverse - " << endl;
    LevelTreeTraverse(root);
    
    cout << endl;
    cout << "Preorder Tree Traverse -" <<endl;
    TraverseTreePreorder(root);

	return 0;
}


