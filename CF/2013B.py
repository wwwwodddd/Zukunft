for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	print(a[-1] - a[-2] + sum(a[:-2]))