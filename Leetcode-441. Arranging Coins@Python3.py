class Solution:
    def arrangeCoins(self, n: int) -> int:
        def getSum(n):
            return n * (n + 1) // 2
        
        left = 0
        right = n

        while left <= right:
            mid = (left + right) // 2
            currentSum = getSum(mid)

            if currentSum == n:
                return mid
            elif currentSum > n:
                right = mid - 1
            else:
                left = mid + 1

        return right