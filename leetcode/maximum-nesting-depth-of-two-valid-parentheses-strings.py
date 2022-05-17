class Solution:
    def maxDepthAfterSplit(self, s: str) -> List[int]:
        a = []
        d = 0
        for i in s:
            if i == '(':
                a.append(d % 2)
                d += 1
            else:
                d -= 1
                a.append(d % 2)
        return a