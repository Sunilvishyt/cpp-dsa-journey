/******************************************************************************
Question : Remove Nth Node From End of List (Leetcode : 19) 
Description : Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* temp = head;
            int count = 0;

            //count the total nodes
            while(temp != nullptr){
                count++;
                temp = temp->next;
            }
            
            //minus the n from the count variable.
            count -= n;

            //if count is 0 means we have to remove HEAD
            if (count == 0){
                temp = head;
                head = head->next;
                return head;
            }

            //if count is more than 0 then we need to remove other node.
            ListNode* curr = head;           
            ListNode* prev = nullptr;

            while(count >= 1){
                prev = curr;
                curr = curr->next;
                count -=1;
            }

            prev->next = curr->next;
            return head;
    }
};
