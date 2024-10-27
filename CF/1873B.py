for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	a[0] += 1
	z = 1
	for i in a:
		z *= i
	print(z)