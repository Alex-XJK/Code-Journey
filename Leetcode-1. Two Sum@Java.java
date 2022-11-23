class Solution {
    public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        int[] complement = new int[length];
        // Build complement
        for(int i = length - 1; i >= 0; i--) {
            complement[i] = target - nums[i];
        }
        // O(N^2) loop to find targe
        for(int i = 0; i < length; i++) {
            int current = nums[i];
            for(int j = 0; j < length; j++) {
                if(i == j) {
                    continue;
                }
                if(current == complement[j]) {
                    int[] result = {i, j};
                    return result;
                }
            }
        }
        return null;
    }
}