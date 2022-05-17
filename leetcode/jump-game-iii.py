class Solution:
    def canReach(self, a: List[int], s: int) -> bool:
        d = [-1 for i in a]
        q = deque()
        q.append(s)
        d[s] = 0
        while len(q):
            i = q.popleft()
            if a[i] == 0:
                return True
            if i - a[i] >= 0 and d[i - a[i]] == -1:
                d[i - a[i]] = d[i] + 1
                q.append(i - a[i])
            if i + a[i] < len(a) and d[i + a[i]] == -1:
                d[i + a[i]] = d[i] + 1
                q.append(i + a[i])
        return False
