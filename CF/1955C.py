for t in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	if sum(a) <= k:
		print(n)
	else:
		x = (k + 1) // 2
		y = k // 2
		i = 0
		j = n - 1
		while x >= a[i]:
			x -= a[i]
			i += 1
		while y >= a[j]:
			y -= a[j]
			j -= 1
		print(n - 1 - j + i)