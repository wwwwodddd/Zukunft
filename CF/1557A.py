for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	print(a[-1] + sum(a[:-1]) / (n - 1))