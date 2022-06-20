class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        pool = set(words)
        
        for word in words:
            for i in range(1, len(word)):
                temp = word[i:]
                if temp in pool:
                    pool.discard(temp)

        addPound = lambda l: len(l) + 1
        result = sum(addPound(word) for word in pool)
        
        return result