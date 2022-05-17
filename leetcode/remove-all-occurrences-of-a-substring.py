class Solution:
    def removeOccurrences(self, s: str, p: str) -> str:
        while p in s:
            s=s.replace(p,'',1)
        return s