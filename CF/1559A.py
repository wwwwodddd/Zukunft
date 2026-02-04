for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = a[0]
	for i in a:
		z &= i
	print(z)
