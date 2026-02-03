for t in range(int(input())):
	n = int(input())
	o, e = 0, 0
	for i in range(1, n + 1):
		if n % i == 0:
			if i % 2:
				o += 1
			else:
				e += 1
	print(o, e)