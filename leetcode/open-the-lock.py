import collections
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        v = [0 for i in range(10000)]
        d = [10000 for i in range(10000)]
        d[0] = 0
        for i in deadends:
            v[int(i)] = 1
        q = collections.deque()
        q.append(0)
        while len(q) > 0:
            u = q[0]
            q.popleft()
            if v[u] == 1:
                continue
            v[u] = 1
            for i in range(4):
                c = [u % 10, u // 10 % 10, u // 100 % 10, u // 1000 % 10]
                c[i] -= 1
                c[i] %= 10
                t = c[0] + c[1] * 10 + c[2] * 100 + c[3] * 1000
                if d[t] > d[u] + 1:
                    d[t] = d[u] + 1
                    q.append(t)
                c = [u % 10, u // 10 % 10, u // 100 % 10, u // 1000 % 10]
                c[i] += 1
                c[i] %= 10
                t = c[0] + c[1] * 10 + c[2] * 100 + c[3] * 1000
                if d[t] > d[u] + 1:
                    d[t] = d[u] + 1
                    q.append(t)

        if d[int(target)] == 10000:
            return -1
        return d[int(target)]