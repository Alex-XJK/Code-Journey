class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        temp = 0
        runningSum = []
        for num in nums:
            temp += num
            runningSum.append(temp)
        return runningSum