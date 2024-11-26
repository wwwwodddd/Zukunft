for t in range(int(input())):
	n, x = map(int, input().split())
	a = sorted(map(int, input().split()))
	print(a[-x] - 1)
