/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode reverseList(ListNode head) {
        //Previous node start as null & Current as head
        ListNode prev = null;
        ListNode curr = head;
        //Traverse until the end of the list
        while(curr != null){
            //save the next node before changing pointers
            ListNode next = curr.next;

            //Reverse curr's pointer to prev
            curr.next = prev;

            //Move prev and curr one step forward
            prev = curr;
            curr = next;
        }
        //Prev becoes the new head after reverseing
        return prev;
    }
}
