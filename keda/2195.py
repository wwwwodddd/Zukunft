n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
for i in range(n):
	a[i + 1] += a[i]
for i in range(m):
	l, r = map(int, input().split())
	print(a[r] - a[l - 1])