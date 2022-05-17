class Solution:
    def isAdditiveNumber(self, s: str) -> bool:
        for i in range(1,len(s)+1):
            for j in range(i+1,len(s)+1):
                x = int(s[:i])
                y = int(s[i:j])
                t = str(x) + str(y) 
                x, y = y, x + y
                t += str(y)
                while len(t) < len(s):
                    x, y = y, x + y
                    t += str(y)
                if t == s:
                    return True
        return False