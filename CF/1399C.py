for t in range(int(input())):
	n = int(input())
	c = [0 for i in range(n * 3)]
	d = [0 for i in range(n * 3)]
	for i in map(int, input().split()):
		c[i] += 1
	for i in range(1, n + 1):
		d[i + i] += c[i] // 2
		for j in range(i + 1, n + 1):
			d[i + j] += min(c[i], c[j])
	print(max(d))