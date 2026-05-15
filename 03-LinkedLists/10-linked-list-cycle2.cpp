/******************************************************************************
Question : Linked List Cycle 2 (LeetCode : 142) 
Description : Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
time complexity : O(n)
space complexity : O(1)
*******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL and fast->next != NULL){
          //update pointers first then check if condition other wise it will always be true.
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast){  //when the pointes meet we have to put head in slow and move them untill the meet again and position will be the starting of the cycle
                slow = head;
                while (slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }

        }
        return nullptr;
    }
};

