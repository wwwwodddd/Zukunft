for t in range(int(input())):
	n, x, k = map(int, input().split())
	print(min(n, k // x))