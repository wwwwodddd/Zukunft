class Solution:
    def restoreString(self, s: str, a: List[int]) -> str:
        b=['']*len(a)
        for i in range(len(a)):
            b[a[i]]=s[i]
        return ''.join(b)