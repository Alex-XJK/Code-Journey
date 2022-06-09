class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        isFind = False
        while left < right and not isFind:
            res = numbers[left] + numbers[right]
            if res == target:
                isFind = True
            elif res > target:
                right -= 1
            else:
                left += 1
        return [left + 1, right + 1]