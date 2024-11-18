for t in range(int(input())):
	n = int(input())
	z = ''
	c = [0 for i in range(n)]
	for i in map(int, input().split()):
		z += chr(c[i] + 97)
		c[i] += 1
	print(z)
