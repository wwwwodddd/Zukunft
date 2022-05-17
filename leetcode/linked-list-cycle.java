/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) {
            return false;
        }
        ListNode a = head;
        ListNode b = head;
        while (true) {
            a = a.next;
            b = b.next;
            if (b == null) {
                return false;
            }
            b = b.next;
            if (b == null) {
                return false;
            }
            if (a == b) {
                return true;
            }
        }
    }
}