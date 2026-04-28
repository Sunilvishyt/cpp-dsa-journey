/******************************************************************************
Question : Rotate List (Leetcode : 61) 
Description : Given the head of a linked list, rotate the list to the right by k places.
time complexity : O(n)
space complexity : O(1)

*******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //if head is null or head->next is null then no need to rotate.
        if (head == nullptr or head->next == nullptr)
            return head;
        
        //count the nodes
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            count += 1;
            temp = temp->next;
        }

        //find the real number of rotations
        int rotations = k % count;

        //initialize slow and fast pointer
        ListNode* slow = head;
        ListNode* fast = head;

        //move the fast pointer
        for (int i = 0; i < rotations; i++){
            fast = fast->next;
        }

        //move slow and fast pointer untill the end
        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        //link the end(fast) pointer to the startting and update head
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
    }
};
