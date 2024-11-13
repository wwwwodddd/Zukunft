for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = a.index(1) + n - 1 - a.index(n)
	if z >= n:
		z -= 1
	print(z)