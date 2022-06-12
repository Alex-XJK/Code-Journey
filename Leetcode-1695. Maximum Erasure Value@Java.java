class Solution {
    private static int EXIST = 1;
    private static int EMPTY = 0;
    private static int RANGE = 10004;
    
    public int maximumUniqueSubarray(int[] nums) {
        final int LEN = nums.length;
        
        int left = 0;
        int right = 0;
        int maxsum = 0;
        int tempsum = 0;
        
        int[] set = new int[RANGE];
        
        while (right < LEN) {
            if (set[nums[right]] == EMPTY) {
                set[nums[right]] = EXIST;
                tempsum += nums[right];
                maxsum = Math.max(maxsum, tempsum);
                right += 1;
            }
            else {
                tempsum -= nums[left];
                set[nums[left]] = EMPTY;
                left += 1;
            }
        }
        
        return maxsum;
    }
}