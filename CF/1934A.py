for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	print(a[-1] * 2 + a[-2] * 2 - a[1] * 2 - a[0] * 2)