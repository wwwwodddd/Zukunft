for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	z = 0
	s = 0
	for i in range(n):
		z = max(z, (s + (n - i) * a[i]) * 20 - (i * a[i] - s) * 30)
		s += a[i]
	print(z)