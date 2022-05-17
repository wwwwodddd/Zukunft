class Solution:
    def minOperations(self, a: List[int], b: List[int]) -> int:
        if sum(a) < sum(b):
            a, b = b, a
        d = sum(a) - sum(b)
        c = sorted([i-1 for i in a] + [6-i for i in b], reverse=True)
        z = 0
        if d == 0:
            return 0
        for i in c:
            d -= i
            z += 1
            if d <= 0:
                return z
        return -1