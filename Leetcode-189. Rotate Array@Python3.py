class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        k = k % length
        """
        [1,2,3,4,5,6,7] (k = 3)
        [1,2,3,4 || 5,6,7]
        [4,3,2,1 || 5,6,7]
        [4,3,2,1 || 7,6,5]
        [4,3,2,1,7,6,5]
        [5,6,7,1,2,3,4]
        """
        nums[0 : length - k] = list(reversed(nums[0 : length - k]))
        nums[length - k : length]  = list(reversed(nums[length - k : length]))
        nums.reverse()