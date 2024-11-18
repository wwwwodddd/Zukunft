for t in range(int(input())):
	a = list(map(int, input().split()))
	print(max(a) - min(a))