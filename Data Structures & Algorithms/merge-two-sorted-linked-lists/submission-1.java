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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        //dummy for handling head
        ListNode dummy = new ListNode(-1);
        //Tail always points to the last node of merged list
        ListNode tail = dummy;
        //Compare nodes until one list becomes empty
        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                tail.next = list1; //attach smaller node
                list1 = list1.next; //move list1 forward
            }else{
                tail.next = list2;//attach smaller
                list2 = list2.next;//move
            }
            //Move tail to the newly added node
            tail = tail.next;
        }
        //Attach remaining nodes 
        if(list1 != null){
            tail.next = list1;
        }else{
            tail.next = list2;
        }

        //return actual head;
        return dummy.next;
    }
}