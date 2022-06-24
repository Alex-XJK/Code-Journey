# [LeetCode-RE] Runtime Error.
# @example  [2]
# @see      https://leetcode.com/submissions/detail/730076073/
# @since    June 24, 2022

# This solution is borrowed from "https://github.com/luliyucoordinate/Leetcode/"
# Hope to implement this question again in Java when I fully understand :(

class Solution:
    def isPossible(self, target: List[int]) -> bool:
        q, s = [], 0
        for i in target:
            heapq.heappush(q, -i)
            s += i

        while True:
            pre = -heapq.heappop(q)
            s -= pre
            if pre == 1 or s == 1:
                return True
            if pre < s or pre % s == 0:
                return False
            
            pre %= s
            s += pre
            heapq.heappush(q, -pre)