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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * i = list1;
        ListNode * j = list2;
        ListNode * dummy = new ListNode(-1);
        ListNode * curr = dummy;

        while(i != NULL && j!= NULL){

            if(i->val < j->val){
                curr->next = new ListNode(i->val);
                i = i->next;
            }
            else{
                curr->next = new ListNode(j->val);
                j = j->next;
            } 
            curr = curr->next;
        }
        if (i) {curr->next = i;}
        if(j){curr->next = j;}

        return dummy->next;
    }
};
