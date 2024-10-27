for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	c = 0
	for i in range(n):
		if a[i] < 0:
			c ^= 1
			a[i] = -a[i]
	a.sort()
	if c:
		a[0] = -a[0]
	print(sum(a))