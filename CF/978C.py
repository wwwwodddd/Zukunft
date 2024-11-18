import bisect
n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
for i in range(n):
	a[i + 1] += a[i]
for i in map(int, input().split()):
	p = bisect.bisect_left(a, i)
	print(p, i - a[p - 1])