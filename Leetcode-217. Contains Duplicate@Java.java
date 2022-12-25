class Solution {
    public boolean containsDuplicate(int[] nums) {
       Set<Integer> set = new HashSet<>();
        
       for (int i = nums.length - 1; i >= 0; i--) {
          if (!set.add(nums[i])) {
             return true;
          }
       }
        
       return false; 
    }
}