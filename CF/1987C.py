for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in range(n):
		z = max(z, a[i] + i)
	print(z)