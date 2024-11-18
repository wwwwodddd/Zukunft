for t in range(int(input())):
	n, k = map(int, input().split())
	a = sorted(map(int, input().split()), reverse=True)
	z = 0
	for i in range(n):
		if i & 1:
			t = min(a[i - 1] - a[i], k)
			k -= t
			z -= a[i] + t
		else:
			z += a[i]
	print(z)