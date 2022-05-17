class Solution:
    def isDecomposable(self, s: str) -> bool:
        l = ''
        c = 0
        a = []
        for i in s:
            if i == l:
                c += 1
            else:
                a.append(c)
                l = i
                c = 1
        a.append(c)
        c = 0
        for i in a:
            if i % 3 == 1:
                return False
            if i % 3 == 2:
                c += 1
        return c == 1
            
        
        