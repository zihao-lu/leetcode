/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.77%)
 * Total Accepted:    1M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* head1=l1;
        ListNode* head2=l2;
        ListNode* temp;
        int carry=0;
        while(l1 && l2){
            int bitsum=l1->val+l2->val+carry;
            l1->val=bitsum%10;
            carry=bitsum/10;
            temp=l1;
            l1=l1->next;
            l2=l2->next;
        }
        if(!l1 && !l2){
            if(carry!=0){
                temp->next= new ListNode(carry);
                temp->next->next=NULL;
            }
        }
        else{
            if(l2)
                l1=l2;
            temp->next=l1;
            while(l1){
                int bitsum=l1->val+carry;
                l1->val=bitsum%10;
                carry=bitsum/10;
                if(!l1->next)
                    temp=l1;
                l1=l1->next;
            }
            
            if(carry!=0){
                temp->next= new ListNode(carry);
                temp->next->next=NULL;
            }
        }
        return head1;
    }
};
