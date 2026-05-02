/******************************************************************************
Question : Palindrome Linked List (LeetCode : 234) 
Description : Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
time complexity : O(n)
space complexity : O(1)

*******************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //count the total number of nodes.
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }

        //if the size if 1 then it will always be palindrome.
        if (count < 2) return true;

        //divide count by two.
        count /= 2;

        //move pointer to the starting of the second half.
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(count--){
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;

        //reverse from the second half to the end.
        prev = nullptr;
        ListNode* next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //then compare both halfs.
        ListNode* left = head;
        ListNode* right = prev;
        while(left){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
