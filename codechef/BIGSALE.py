for t in range(int(input())):
	n = int(input())
	s = 0
	for i in range(n):
		x, y, z = map(int, input().split())
		s += x * y * (z / 100) ** 2
	print(s)