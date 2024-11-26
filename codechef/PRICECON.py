for t in range(int(input())):
	n, h = map(int, input().split())
	print(sum(max(int(i) - h, 0) for i in input().split()))
