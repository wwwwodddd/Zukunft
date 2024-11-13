for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	print(a.index(min(a)) + 1)
