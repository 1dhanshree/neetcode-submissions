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
        //Take prev as null and curr as head;
        ListNode curr = head;
        ListNode prev = null;

        //Traverse till the end of the list
        while(curr!= null){
            //save the next node before changing pointers
            ListNode next = curr.next;

            //reverse the curr pointer from next to prev
            curr.next = prev;
            //Move prev and curr one step forward
            prev = curr;
            curr = next;
        }
        //prev becoes new head
        return prev;
    }
}
