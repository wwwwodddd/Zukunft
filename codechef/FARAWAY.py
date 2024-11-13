for t in range(int(input())):
	n, m = map(int, input().split())
	print(sum(max(i - 1, m - i) for i in map(int, input().split())))