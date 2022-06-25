class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        change = 0
        length = len(nums)
        for i in range(length - 1):
            if nums[i] <= nums[i + 1]:
                continue
            else:
                if i == 0 or i == length - 2:
                    change += 1
                elif nums[i - 1] <= nums[i + 1]:
                    # 1 4 3 x (4 > 3, 1 < 3, decrease 4) --> 1 2 3 x 
                    change += 1
                elif nums[i] <= nums[i + 2]:
                    # x 3 1 4 (3 > 1, 4 > 3, increase 1) --> x 3 3 4
                    change += 1
                else:
                    return False
                
            if change > 1:
                return False
                
        return True