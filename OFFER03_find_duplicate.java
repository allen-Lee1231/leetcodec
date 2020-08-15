import java.util.*;


class Solution {
    public int findRepeatNumber(int[] nums) {
        /*
        if (nums.length <= 1){
            System.out.println("No duplicates!");
            return -1;
        }
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
        for (int i: nums){
            if (ht.containsKey(i)){
                return i;
            }
            ht.put(i, 1);
        }
        System.out.println("No duplicates!");
        return -1;
        */
        if (nums.length <= 1){
            System.out.println("No duplicates!");
            return -1;
        }

        int[] aryRersult = new int[nums.length];
        Arrays.fill(aryRersult, 0);
        for (int i: nums){
            if (aryRersult[i] != 0){
                return i;
            }
            aryRersult[i] += 1;
        }
        System.out.println("No duplicates!");
        return -1;
    }
}