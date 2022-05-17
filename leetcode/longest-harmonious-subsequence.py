class Solution:
    def findLHS(self, a: List[int]) -> int:
        c = Counter(a)
        z = 0
        for i in c:
            if i in c and i + 1 in c:
                z = max(z, c[i] + c[i + 1])
        return z