class Solution:
    def maxSlidingWindow(self, a: List[int], k: int) -> List[int]:
        q = deque()
        z = []
        for i in range(len(a)):
            while len(q) and a[q[-1]] <= a[i]:
                q.pop()
            q.append(i)
            while q[0] <= i-k:
                q.popleft()
            if i>=k-1:
                z.append(a[q[0]])
        return z