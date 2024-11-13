for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	print(min(y - x for x, y in zip(a, a[1:])))
