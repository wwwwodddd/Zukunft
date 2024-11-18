for t in range(int(input())):
	n = int(input())
	c = list(map(int, input().split())).count(-1)
	z = 0
	if c & 1:
		c -= 1
		z += 1
	while c * 2 > n:
		c -= 2
		z += 2
	print(z)