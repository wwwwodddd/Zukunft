for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	z = sum(sorted(a)[:2])
	for i in range(1, len(a)):
		z = min(z, a[i - 1] + a[i] // 2)
	print(z)