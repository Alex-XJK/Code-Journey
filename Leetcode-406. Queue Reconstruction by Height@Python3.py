# With respect to {@author YJL1228}'s solution.
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # sort the people from tall to short
        # insert from tall to short (insert at index = p[1])
        people.sort(key=lambda p: (-p[0], p[1]))
        result = []
        for p in people:
            result.insert(p[1], p)
        return result