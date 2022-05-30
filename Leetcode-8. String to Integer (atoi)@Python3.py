class Solution:
    def myAtoi(self, s: str) -> int:
        
        crop_str = s.strip() 
        if not crop_str:
            return 0
        
        sign = 1
        if crop_str[0] in ["+", "-"]:
            if crop_str[0] == "-":
                sign = -1
            crop_str = crop_str[1:]
            
        answer = 0
        for c in crop_str:
            if c.isdigit():
                answer *= 10
                answer += int(c)
            else:
                break
        answer *= sign
        
        if answer > (2**31 - 1):
            return (2**31 - 1)
        if answer < (-2**31):
            return (-2**31)
        return answer