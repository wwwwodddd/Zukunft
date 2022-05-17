class Solution:
    def findLucky(self, a: List[int]) -> int:
        c=Counter(a)
        for i in sorted(c.keys(),reverse=True):
            if c[i]==i:
                return i
        return -1