for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in range(n):
		z += a[i] * (i + 1)
	print(z)
