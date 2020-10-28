/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 *
 * Follow up:
 *
 * Could you solve the problem in O(1) extra memory space?
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
 *
 *
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode lStart, ListNode lEnd) {
        if (lStart == lEnd) {
            return lStart;
        }
        ListNode head = reverseListPart(lStart.next, lEnd);
        head.next = lStart;
        return lStart;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode lStart = head;
        ListNode lEnd = head;
        for (int i = 1; i < k; i++) {
            if (lEnd == null || lEnd.next == null) {
                return lStart;
            }

            lEnd = lEnd.next;
        }

        ListNode lNext = reverseKGroup(lEnd.next, k);
        lStart = reverseList(lStart, lEnd);
        lStart.next = lNext;
        return lEnd;
    }
}
