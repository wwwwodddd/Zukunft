for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	print((max(a) - min(a)) * (n - 1))