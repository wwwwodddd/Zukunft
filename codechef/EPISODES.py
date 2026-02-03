for t in range(int(input())):
	n, k = map(int, input().split())
	print(n * k // 60, n * k % 60)
