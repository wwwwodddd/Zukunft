class Solution:
    def canFinish(self, n: int, e: List[List[int]]) -> bool:
        d = [0 for i in range(n)]
        a = [[] for i in range(n)]
        for x, y in e:
            a[x].append(y)
            d[y] += 1
        q = deque()
        for i in range(n):
            if d[i] == 0:
                q.append(i)
        while len(q):
            u = q.pop()
            for i in a[u]:
                d[i] -= 1
                if d[i] == 0:
                    q.append(i)
        return sum(d) == 0