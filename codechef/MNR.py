for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	print(min(a[-1] - a[2], a[-2] - a[1], a[-3] - a[0]))