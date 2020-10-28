// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
//
//        You can return the answer in any order.
//        Example 1:
//
//        Input: s = "barfoothefoobarman", words = ["foo","bar"]
//        Output: [0,9]
//        Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
//        The output order does not matter, returning [9,0] is fine too.
//        Example 2:
//
//        Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//        Output: []
//        Example 3:
//
//        Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//        Output: [6,9,12]

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        int nSLen = words[0].length();
        int nLen = words.length;
        int nSubstrLen = nSLen * nLen;

        List<Integer> lResult = new ArrayList();
        HashMap<String, Integer> hmTarget = new HashMap();
        for (int j = 0; j < nLen; j ++) {
            Integer nCount = hmTarget.putIfAbsent(words[j], 1);
            if (nCount != null) {
                hmTarget.put(words[j], nCount+1);
            }
        }

        for (int i = 0; i <= s.length() - nSubstrLen; i ++) {
            HashMap<String, Integer> hmS = new HashMap();
            String substr = s.substring(i, i + nSubstrLen);
            //System.out.printf("%s\n", substr);
            for (int j = 0; j < nSubstrLen; j += nSLen) {
                Integer nCount = hmS.putIfAbsent(substr.substring(j, j+nSLen), 1);
                if (nCount != null) {
                    hmS.put(substr.substring(j, j+nSLen), nCount+1);
                }
            }

            if (hmS.equals(hmTarget)) {
                lResult.add(i);
            }
        }
        return lResult;
    }
}