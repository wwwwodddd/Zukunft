for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	z = 0
	for i in range(n):
		z = max(z, a[i] * (n - i))
	print(z)