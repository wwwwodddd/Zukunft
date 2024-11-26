for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	z = 0
	for i in range(1, len(a)):
		z += abs(a[i] - a[i - 1]) - 1
	print(z)