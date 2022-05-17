class Solution:
    def maxSumDivThree(self, a: List[int]) -> int:
        f = [0, 0, 0]
        for i in a:
            for j in f[:]:
                f[(j + i) % 3] = max(f[(j + i) % 3], j + i)
        return f[0]