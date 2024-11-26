for t in range(int(input())):
	n, x = map(int, input().split())
	print(max(n * x - sum(map(int, input().split())), 0))
