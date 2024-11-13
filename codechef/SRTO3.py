for t in range(int(input())):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	x = max(map(int, input().split()))
	print(*a[:-x], *sorted(a[-x:]))