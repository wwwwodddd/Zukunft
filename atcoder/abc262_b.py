n, m = map(int, input().split())
a = [set() for i in range(n + 1)]
for i in range(m):
    x, y = map(int, input().split())
    a[x].add(y)
z = 0
for i in range(1, n + 1):
    for j in a[i]:
        z += len(a[i] & a[j])
print(z)
