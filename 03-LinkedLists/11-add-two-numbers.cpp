/******************************************************************************
Question : Add Two Numbers (LeetCode : 2) 
Description : You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
      You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *first = l1;
        ListNode *second = l2;
        ListNode *head = new ListNode(0); //dummy node for creating the answer list and evading many if else statements.
        ListNode *tail = head;
        int carry = 0;

        //while both first and second nodes are there add both values and save it in the head (answer).
        while (first and second){
            int sum = first->val + second->val + carry;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            first = first -> next;
            second = second ->next;
            carry = sum / 10;
        }

        //if first or second even one of them remains add them in the answer.
        while (first){
            int sum = first->val + carry;
            tail -> next = new ListNode(sum % 10);
            tail = tail->next;
            first = first -> next;
            carry = sum / 10;
        }

        while (second){
            int sum = second->val + carry;
            tail -> next = new ListNode(sum % 10);
            tail = tail->next;
            second = second -> next;
            carry = sum / 10;
        }

    //after all that if carry remains than we have to create a new node for it too in the answer 
        while (carry){
            tail->next = new ListNode(carry);
            carry = carry / 10;
        }

        //return answer.
        return head->next;
    }
};
