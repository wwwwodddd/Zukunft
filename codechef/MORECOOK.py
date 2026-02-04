for t in range(int(input())):
	n, c = map(int, input().split())
	s = set(map(int, input().split()))
	z = 0
	while c in s or c < min(s):
		c += 1
		z += 1
	print(z)