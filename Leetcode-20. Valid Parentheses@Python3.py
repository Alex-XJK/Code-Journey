class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        dict = {'(': ')', 
                '[': ']', 
                '{': '}'}
        for char in s:
            if char in dict:
                stack.append(dict[char])
            else:
                if stack == [] or char != stack.pop():
                    return False
                
        return stack == []
        