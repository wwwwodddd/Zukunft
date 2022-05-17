class Solution:
    def minimumEffort(self, a: List[List[int]]) -> int:
        a.sort(key=lambda x:x[1]-x[0])
        s=0
        for x,y in a:
            s=max(s+x,y)
        return s