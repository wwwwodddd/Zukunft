for t in range(int(input())):
	n = int(input())
	z = 0
	for i in range(n):
		s, p, v = map(int, input().split())
		z = max(z, p // (s + 1) * v)
	print(z)