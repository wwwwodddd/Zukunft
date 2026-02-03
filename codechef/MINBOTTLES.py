for t in range(int(input())):
	n, x = map(int, input().split())
	print((sum(map(int, input().split())) + (x - 1)) // x)