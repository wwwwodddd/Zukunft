p = 1000000007
for t in range(int(input())):
	h, n = map(int, input().split())
	a = list(map(int, input().split()))
	c = list(map(int, input().split()))
	L = -1
	R = h * 200000
	def ok(m):
		s = 0
		for i in range(n):
			s += (m // c[i] + 1) * a[i]
		return h <= s
	while L < R - 1:
		M = (L + R) // 2
		if ok(M):
			R = M
		else:
			L = M
	print(R + 1)