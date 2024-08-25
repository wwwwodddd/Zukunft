import sys
sys.setrecursionlimit(200000)
n, m = map(int, input().split())
p = list(map(int, input().split()))
a = [[] for i in range(n)]
for i in range(1, n):
    x, y = map(int, input().split())
    a[x].append(y)
    a[y].append(x)

s = [0 for i in range(n)]
for i in p:
    s[i] = 1

z = 0
f = 0

def dfs(x, y):
    global z, f
    r = 0
    for i in a[x]:
        if i != y:
            t = dfs(i, x) + 1
            if s[i] > 0:
                z += 1
                f = max(f, r + t)
                r = max(r, t)
            s[x] += s[i]
    return r

dfs(p[0], -1)
print(z * 2 - f)