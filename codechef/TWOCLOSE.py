for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	x = a.pop()
	a.sort()
	for i in range(n):
		if x < a[i] <= x * 2:
			x, a[i] = a[i], x
	print(sum(a))