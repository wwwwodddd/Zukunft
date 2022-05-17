class Solution:
    def findOrder(self, n: int, e: List[List[int]]) -> List[int]:
        d = [0 for i in range(n)]
        a = [[] for i in range(n)]
        for x, y in e:
            a[y].append(x)
            d[x] += 1
        q = []
        for i in range(n):
            if d[i] == 0:
                q.append(i)
        j = 0
        while j < len(q):
            u = q[j]
            j += 1
            for i in a[u]:
                d[i] -= 1
                if d[i] == 0:
                    q.append(i)
        if len(q) < n:
            q = []
        return q