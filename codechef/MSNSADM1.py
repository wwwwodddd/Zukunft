for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	z = 0
	for i in range(n):
		z = max(z, a[i] * 20 - b[i] * 10)
	print(z)