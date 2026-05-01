/******************************************************************************
Question : Remove every k'th node (GFG) 
Description : Given a singly linked list, your task is to remove every kth node from the linked list. 
time complexity : O(n)
space complexity : O(1)

*******************************************************************************/


/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
        int count = 1;
        Node* prev = NULL;
        Node* curr = head;
        
        Node* temp = head;
        while (curr){
            if (count == k){
                prev->next = curr->next;
                curr = curr->next;
                count = 1;
            }
            
            else {
                count += 1;
                prev = curr;
                curr = curr->next;
            }
 
        }
        
        return head;
    }
};
