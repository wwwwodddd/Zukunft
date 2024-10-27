for t in range(int(input())):
	n, l, r = map(int, input().split())
	a = sorted(map(int, input().split()))
	j, k = 0, 0
	i = n - 1
	z = 0
	while j < i:
		while k < i and a[k] + a[i] <= r:
			k += 1
		while j < i and a[j] + a[i] < l:
			j += 1
		z += min(k, i) - j
		i -= 1
	print(z)