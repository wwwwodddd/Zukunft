n = int(input())
a = list(map(int, input().split())) + [0]
m = int(input())
for i in range(n)[::-1]:
	a[i + 1] -= a[i]
for i in range(m):
	x, y, z = map(int, input().split())
	a[x - 1] += z
	a[y] -= z
for i in range(n):
	a[i + 1] += a[i]
print(*a[:-1])