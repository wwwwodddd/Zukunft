import bisect
n, q = map(int, input().split())
a = list(map(int, input().split()))
for i in range(q):
	x = int(input())
	l = bisect.bisect_left(a, x)
	r = bisect.bisect_right(a, x)
	if l < r:
		print(l, r - 1)
	else:
		print(-1, -1)
