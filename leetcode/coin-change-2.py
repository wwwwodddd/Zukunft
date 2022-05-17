class Solution:
    def change(self, n: int, a: List[int]) -> int:
        f = [0 for i in range(n+1)]
        f[0] = 1
        for i in a:
            for j in range(i,n+1):
                f[j] += f[j-i]
        return f[n]