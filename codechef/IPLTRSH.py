for t in range(int(input())):
	n, m = map(int, input().split())
	print(max(n - m, 0))
