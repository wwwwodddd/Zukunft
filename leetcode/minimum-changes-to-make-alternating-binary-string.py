class Solution:
    def minOperations(self, s: str) -> int:
        c=sum(int(s[i])!=i%2 for i in range(len(s)))
        return min(c,len(s)-c)