class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        s = mean * (n + m) - sum(rolls)
        if s < n or s > n * 6:
            return []
        a = [1 for i in range(n)]
        s -= n
        for i in range(n):
            t = min(s, 5)
            s -= t
            a[i] += t
        return a