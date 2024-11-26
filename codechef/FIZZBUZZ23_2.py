for t in range(int(input())):
	n, x, d = map(int, input().split())
	print(n // 5 // x + d)