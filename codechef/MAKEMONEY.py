for t in range(int(input())):
	n, x, c = map(int, input().split())
	print(sum(max(int(i), x - c) for i in input().split()))
