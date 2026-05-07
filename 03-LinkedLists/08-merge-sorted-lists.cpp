/******************************************************************************
Question : Merge Two Sorted Lists (LeetCode : 21) 
Description : You are given the heads of two sorted linked lists list1 and list2.
          Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
          Return the head of the merged linked list.
time complexity : O(n)
space complexity : O(n+m)

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

// solution by creating new nodes (no inplace changin)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        //if both lists exists compare lists elements untill one of the lists become null (empty)
        while(list1 and list2){
            if (list1->val <= list2->val){
                //if head is not null then attach in curr->next because curr and head poing to same list
                if (head){
                    curr->next = new ListNode(list1->val);
                    curr = curr->next;
                }
                //else create new list in head.
                else {
                    head = new ListNode(list1->val);   
                    curr = head;
                }
                list1 = list1->next;
            }

            else {
                if (head){
                    curr->next = new ListNode(list2->val);
                    curr = curr->next;
                }
                else {
                    head = new ListNode(list2->val);   
                    curr = head;
                }
                list2 = list2->next;
            }

        }

        //if list1 got null and elements are there in list2 then connect the whole list two in head or curr
        if (!list1 and list2){
            //if head is empty then while loop didn't run so connect the list two with head otherwise in curr->next.
            if (!head)
                head = list2;
            else curr->next = list2;
        }
        
        if (!list2 and list1){
            if (!head)
                head = list1;
            else
                curr->next = list1;
        }

        return head;

    }
};
