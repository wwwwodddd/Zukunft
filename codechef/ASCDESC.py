n, k = map(int, input().split())
b = int(n ** 0.5)
a = list(range(1, n + 1))
z = []
for i in range(b)[::-1]:
	z += a[i::b]
print(*z)
