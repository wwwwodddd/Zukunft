class Solution:
    def countSteppingNumbers(self, l: int, h: int) -> List[int]:
        z = []
        if l <= 0 <= h:
            z.append(0)
        def dfs(x, d):
            if l <= x <= h:
                z.append(x)
            if x > h:
                return
            if d > 0:
                dfs(x * 10 + d - 1, d - 1)
            if d < 9:
                dfs(x * 10 + d + 1, d + 1)
        for i in range(1, 10):
            dfs(i, i)
        return sorted(z);