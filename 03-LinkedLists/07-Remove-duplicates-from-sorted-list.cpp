/******************************************************************************
Question :Remove Duplicates from a Sorted Linked List (GFG) 
Description : You are given the head of a singly linked list. Remove all duplicate nodes from the list so that each element appears only once.
              Note: Try not to use extra space. The nodes are arranged in a sorted way.
time complexity : O(n)
space complexity : O(1)

*******************************************************************************/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        Node* temp = head;
        
        while(temp != nullptr and temp->next != nullptr){
            if (temp->data == temp->next->data)
                {
                    temp->next = temp->next->next;
                }
            else 
                {
                    temp = temp->next;
                }
        }
        
        return head;
        
    }
};
