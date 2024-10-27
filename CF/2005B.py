import bisect
for t in range(int(input())):
	n, m, q = map(int, input().split())
	b = sorted(map(int, input().split()))
	a = list(map(int, input().split()))
	for i in a:
		if i < b[0]:
			print(b[0] - 1)
		elif i > b[-1]:
			print(n - b[-1])
		else:
			p = bisect.bisect(b, i)
			print((b[p] - b[p - 1]) // 2)