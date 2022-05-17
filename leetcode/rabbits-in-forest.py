class Solution:
    def numRabbits(self, a: List[int]) -> int:
        c = Counter(a)
        z = 0
        for i in c:
            z += (c[i] + i) // (i + 1) * (i + 1)
        return z