for t in range(int(input())):
	n = int(input())
	m = int(input())
	l = int(input())
	a = [input() for i in range(n)]
	b = [input() for i in range(m)]
	c = [input() for i in range(l)]
	for i in a:
		for j in b:
			for k in c:
				print(i, j, k + '.')