class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        z=0
        c=0
        for i in s:
            if i=='(':
                c+=1
            else:
                if c:
                    c-=1
                else:
                    z+=1
        z+=c
        return z