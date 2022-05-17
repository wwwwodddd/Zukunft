class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j = 0
        for i in s:
            if j < len(g) and g[j] <= i:
                j += 1
        return j