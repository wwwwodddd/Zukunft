class Solution:
    def minTimeToType(self, s: str) -> int:
        s='a'+s
        z=0
        for i in range(1,len(s)):
            d=abs(ord(s[i])-ord(s[i-1]))
            z+=min(d,26-d)+1
        return z