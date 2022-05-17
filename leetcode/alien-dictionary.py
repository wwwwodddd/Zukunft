class Solution:
    def alienOrder(self, w: List[str]) -> str:
        a = [[] for i in range(26)]
        d = [0 for i in range(26)]
        v = [0 for i in range(26)]
        for s in w:
            for i in s:
                v[ord(i) - 97] = 1
        for i in range(1, len(w)):
            j = 0
            while True:
                if j == len(w[i - 1]):
                    break
                if j == len(w[i]):
                    return ''
                if w[i - 1][j] != w[i][j]:
                    x = ord(w[i - 1][j]) - 97
                    y = ord(w[i][j]) - 97
                    a[x].append(y)
                    d[y] += 1
                    break
                j += 1
        q = deque()
        for i in range(26):
            if v[i] and d[i] == 0:
                q.append(i)
        z = ''
        while q:
            u = q.popleft()
            z += chr(u + 97)
            for i in a[u]:
                d[i] -= 1
                if d[i] == 0:
                    q.append(i)
        if len(z) < sum(v):
            return ''
        return z