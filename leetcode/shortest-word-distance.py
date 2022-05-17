class Solution:
    def shortestDistance(self, a: List[str], s: str, t: str) -> int:
        n = len(a)
        p = q = -n
        z = n
        for i in range(n):
            if a[i] == s:
                p = i
                z = min(z, p - q)
            if a[i] == t:
                q = i
                z = min(z, q - p)
        return z