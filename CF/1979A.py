for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = [max(x, y) for x, y in zip(a, a[1:])]
	print(min(b) - 1)