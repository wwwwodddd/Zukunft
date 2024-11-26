for t in range(int(input())):
	n, h = map(int, input().split())
	print(sum(int(i) > h for i in input().split()))
