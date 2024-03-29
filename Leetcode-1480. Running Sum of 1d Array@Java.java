class Solution {
    public int[] runningSum(int[] nums) {
        int[] runningNums = new int[nums.length];
        runningNums[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            runningNums[i] = nums[i] + runningNums[i - 1];
        }
        return runningNums;
    }
}