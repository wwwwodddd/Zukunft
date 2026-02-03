for t in range(int(input())):
	n, m = map(int, input().split())
	a = sorted(map(int, input().split()))
	print(*a[m:-1], sum(a[:m]) + a[-1])
