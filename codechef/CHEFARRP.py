for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in range(n):
		x = 0
		y = 1
		for j in range(i, n):
			x += a[j]
			y *= a[j]
			if x == y:
				z += 1
	print(z)