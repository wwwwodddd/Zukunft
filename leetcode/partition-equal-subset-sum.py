class Solution:
    def canPartition(self, a: List[int]) -> bool:
        s = sum(a)
        if s % 2:
            return False
        f = [0 for i in range(s + 1)]
        f[0] = 1
        for i in a:
            for j in range(i, s + 1)[::-1]:
                f[j] |= f[j - i]
        return f[s // 2] == 1