n, k = map(int, input().split())
a = list(map(int, input().split()))
g = {}
z = 0
for i in range(n):
    if a[i] not in g:
         g[a[i]] = 0
    g[a[i]] += 1
    if i >= k:
         g[a[i - k]] -= 1
         if g[a[i - k]] == 0:
             del g[a[i - k]]
    z = max(z, len(g))
print(z)
