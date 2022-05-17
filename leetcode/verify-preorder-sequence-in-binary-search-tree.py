class Solution:
    def verifyPreorder(self, a: List[int]) -> bool:
        p = 0
        def dfs(l, r):
            nonlocal p
            if p < len(a) and l <= a[p] <= r:
                v = a[p]
                p += 1
                dfs(l, v)
                dfs(v, r)            
        dfs(0, 10001)
        return p == len(a)