/*
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
* */
import java.utils.*;


class Solution {
    public int longestValidParentheses(String s) {
        int heapLeft = 0;
        int heapRight = 0;
        boolean[] resultMap = new boolean[s.length()];
        for (int i = 0, j = s.length() - 1; i < s.length(); i++, j--) {
            if (s.charAt(i) == '(') {
                heapLeft++;
            }
            else if (heapLeft > 0) {
                resultMap[i] = true;
                heapLeft--;
            }

            if (s.charAt(j) == ')') {
                heapRight++;
            }
            else if (heapRight > 0) {
                resultMap[j] = true;
                heapRight--;
            }
        }

        int maxLen = 0;
        int paired = 0;
        for (int i = 0; i < resultMap.length; i++) {
            if (!resultMap[i]) {
                maxLen = maxLen < paired? paired: maxLen;
                paired = 0;
            }
            else {
                paired ++;
            }
        }

        return maxLen < paired? paired: maxLen;
    }
}