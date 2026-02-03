def F(a):
	for i in range(1, n):
		if a[i - 1] == a[i]:
			return 0
	z = 1
	for i in range(n):
		for j in range(i + 1, n):
			z *= a[i] ^ a[j]
			if z > r:
				return z
	return z
for t in range(int(input())):
	n, l, r = map(int, input().split())
	a = sorted(map(int, input().split()))
	if l <= F(a) <= r:
		print('YES')
	else:
		print('NO')