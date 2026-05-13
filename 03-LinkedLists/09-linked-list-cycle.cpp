/******************************************************************************
Question : Linked List Cycle (LeetCode : 141) 
Description : Given head, the head of a linked list, determine if the linked list has a cycle in it.
      There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
      Return true if there is a cycle in the linked list. Otherwise, return false.
time complexity : O(n)
space complexity : O(n)

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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>map;

        ListNode* curr = head;
        while(curr != NULL){
            if (map.count(curr)){
                return true;
            }
            map[curr] = 1;
            curr = curr->next;
        }
        return false;
    }
};

/*
note -  to know if the linked list is circular or not we have to check its memory address.
*/
