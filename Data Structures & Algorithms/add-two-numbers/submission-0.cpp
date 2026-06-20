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
        ListNode* i = l1;
        ListNode* j = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;

        while(i != NULL || j != NULL){
            int sum = carry;
            if(i){sum += i->val;}
            if(j){sum += j->val;} 
            ListNode * addN = new ListNode(sum%10);
            carry = sum/10;
            curr->next = addN;
            curr = curr->next;

            if(i) i = i->next;
            if(j) j = j->next;
        }
        if(carry){
            ListNode* addNode = new ListNode(carry);
            curr->next = addNode;
        }
        return dummy->next;
    }
};
