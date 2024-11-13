for t in range(int(input())):
	d, n = map(int, input().split())
	for i in range(d):
		n = n * (n + 1) // 2
	print(n)