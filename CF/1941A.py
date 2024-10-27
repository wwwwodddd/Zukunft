import bisect
for t in range(int(input())):
	n, m, k = map(int, input().split())
	b = sorted(map(int, input().split()))
	c = sorted(map(int, input().split()))
	z = 0
	for i in range(n):
		z += bisect.bisect_right(c, k - b[i])
	print(z)