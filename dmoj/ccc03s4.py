import functools
import array
t = int(input())
p = 1000000016000000063

for _ in range(t):
    s = input()
    n = len(s)
    h = [0 for i in range(n + 1)]
    b = [0 for i in range(n + 1)]
    b[0] = 1
    for i in range(n):
        h[i + 1] = (h[i] * 131 + ord(s[i])) % p
        b[i + 1] = b[i] * 131 % p
    def hsh(l, r): # hash(s[l:r])
        return (h[r] - h[l] * b[r - l]) % p
    def lcp(i, j): # largest d   such that s[i : i + d] == s[j : j + d]
        L = 0
        R = min(n - i, n - j) + 1
        while L < R - 1:
            M = (L + R) // 2
            if hsh(i, i + M) == hsh(j, j + M):
                L = M
            else:
                R = M
        return L

    # f = [array.array('i', [0 for j in range(n + 1)])for i in range(n + 1)]
    # for i in range(n)[::-1]:
    #     for j in range(n)[::-1]:
    #         if s[i] == s[j]:
    #             f[i][j] = f[i + 1][j + 1] + 1
    #             f[i][j] = largest d   such that s[i : i + d] == s[j : j + d]
    s += ' '
    def cmp(x, y): # cmp s[x:] and s[y:]
        # d = f[x][y]
        d = lcp(x, y)
        if s[x + d] < s[y + d]: # if s[x:] < s[y:]  return -1
            return -1
        if s[x + d] > s[y + d]: # if s[x:] > s[y:]  return +1
            return +1
        return 0
    r = list(range(n))
    r.sort(key=functools.cmp_to_key(cmp))
    z = n * (n + 1) // 2 + 1
    for i in range(1, n):
        # z -= f[r[i - 1]][r[i]]
        z -= lcp(r[i - 1], r[i])
    print(z)
