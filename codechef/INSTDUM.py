for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n):
		a[i] -= 1
		if i > 0:
			a[i] += a[i - 1]
	print(a.count(0))
