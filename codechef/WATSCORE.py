for t in range(int(input())):
	n = int(input())
	p = [0 for i in range(12)]
	for i in range(n):
		x, y = map(int, input().split())
		p[x] = max(p[x], y)
	print(sum(p[:9]))