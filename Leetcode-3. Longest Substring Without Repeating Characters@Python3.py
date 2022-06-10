class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = len(s);
        
        left = 0
        right = 0
        
        result = 0

        pool = set()
        
        while right < length:
            if s[right] in pool:
                pool.remove(s[left])
                left += 1
            else:
                pool.add(s[right])
                right += 1
                result = max(result, len(pool))
                
        return result