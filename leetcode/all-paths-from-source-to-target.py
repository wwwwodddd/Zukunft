class Solution:
    def allPathsSourceTarget(self, a: List[List[int]]) -> List[List[int]]:
        n = len(a)
        f = [[]for i in range(n)]
        d = [0 for i in range(n)]
        f[0].append([0])
        for b in a:
            for j in b:
                d[j] += 1
        q = deque()
        for i in range(n):
            if d[i] == 0:
                q.append(i)
        while len(q):
            u = q.popleft()
            for v in a[u]:
                for i in f[u]:
                    f[v].append(i + [v])
                d[v] -= 1
                if d[v] == 0:
                    q.append(v)
        return f[n - 1]
        
        