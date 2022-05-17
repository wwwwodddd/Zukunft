class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        t = set()
        z = 0
        def dfs(i):
            nonlocal z
            if i == len(s):
                z = max(z, len(t))
            for j in range(i + 1, len(s) + 1):
                if s[i:j] not in t:
                    t.add(s[i:j])
                    dfs(j)
                    t.remove(s[i:j])
        dfs(0)
        return z