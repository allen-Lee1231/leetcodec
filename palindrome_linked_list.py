# Given a singly linked list, determine if it is a palindrome.
#
# Example 1:
# Input: 1->2
# Output: false
#
# Example 2:
# Input: 1->2->2->1
# Output: true


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return True

        if head.next.next is None:
            if head.val == head.next.val:
                return True
            else:
                return False

        # get length of the list
        lst_len = 0
        right_cursor = head
        while right_cursor.next is not None:
            right_cursor = right_cursor.next
            lst_len += 1

        center = lst_len // 2

        # reverse top half
        i = 0
        left_cursor = head
        right_cursor = head.next
        temp = right_cursor.next
        while i < center:
            right_cursor.next = left_cursor
            left_cursor = right_cursor
            right_cursor = temp
            temp = temp.next
            i += 1

        # compare
        if lst_len & 1 == 0:
            left_cursor = left_cursor.next
        while i > 0:
            if left_cursor.val != right_cursor.val:
                return False

            left_cursor = left_cursor.next
            right_cursor = right_cursor.next
            i -= 1

        if lst_len & 1:
            if left_cursor.val == right_cursor.val:
                return True
            else:
                return False

        return True
