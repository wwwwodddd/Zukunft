for t in range(int(input())):
	n, x = map(int, input().split())
	a = list(map(int, input().split()))
	print(min(max(a), sum((i + x - 1) // x for i in a)))