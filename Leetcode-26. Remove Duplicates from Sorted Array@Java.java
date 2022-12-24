class Solution {
    public int removeDuplicates(int[] nums) {
        int nextPosition = 0;
        int currentValue = nums[0] - 1;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == currentValue) {
                continue;
            }
            else {
                nums[nextPosition] = nums[i];
                currentValue = nums[i];
                nextPosition += 1;
            }
        }
        return nextPosition;
    }
}