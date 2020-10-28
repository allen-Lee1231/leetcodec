import java.utils.*;

class Solution {
    public List<List<Integer>> bfSum(List<Integer> nums, List<Integer> reserve, int target, int nSum, int sumCount, int start_idx) {
        List<List<Integer>> llResult = new ArrayList();
        if (sumCount == 1) {
            for (int i = start_idx; i < nums.size(); i++) {
                if (nums.get(i)+nSum > target){
                    break;
                }
                if (nums.get(i)+nSum == target) {
                    List<Integer> lTemp = new ArrayList();
                    lTemp.addAll(reserve);
                    lTemp.add(nums.get(i));
                    llResult.add(lTemp);
                }
            }
            return llResult;
        }

        for (int i = start_idx; i < nums.size(); i++) {
            Integer n = nums.get(i);
            if (nums.size()-i < sumCount) {
                break;
            }
            reserve.add(n);
            List<List<Integer>> llTemp = bfSum(nums, reserve, target, nSum+n, sumCount-1, i+1);
            boolean bDuplicate = false;
            for (List<Integer> t: llTemp) {
                for (List<Integer> r: llResult) {
                    if (t.equals(r)) {
                        bDuplicate = true;
                        break;
                    }
                }
                if (!bDuplicate) {
                    llResult.add(t);
                }
                bDuplicate = false;
            }
            reserve.remove(reserve.size()-1);
        }
        return llResult;
    }


    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<Integer> lNums = new ArrayList();
        for (int i = 0; i < nums.length; i++) {
            lNums.add(Integer.valueOf(nums[i]));
        }

        List<Integer> lReserve = new ArrayList();
        List<List<Integer>> llResult = bfSum(lNums, lReserve, target, 0, 4, 0);
        return llResult;
    }
}