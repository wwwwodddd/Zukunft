class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        z = []
        def dfs(x):
            z.append(x)
            for i in range(10):
                if 0 < x * 10 + i <= n:
                    dfs(x * 10 + i)
        dfs(0)
        return z[1:]