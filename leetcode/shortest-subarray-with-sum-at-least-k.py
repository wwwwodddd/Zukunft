class Solution:
    def shortestSubarray(self, a: List[int], k: int) -> int:
        n = len(a)
        z = n + 1
        q = deque()
        s = [0 for i in range(n + 1)]
        for i in range(n):
            s[i + 1] = s[i] + a[i]
        for i in range(n + 1):
            while q and s[i] - s[q[0]] >= k:
                z = min(z, i - q.popleft())
            while q and s[i] <= s[q[-1]]:
                q.pop()
            q.append(i)
        if z == n + 1:
            z = -1
        return z