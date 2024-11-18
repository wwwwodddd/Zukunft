for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	i = 0
	j = n - 1
	z = 0
	while i <= j:
		z += 1
		if i < j and a[i] + a[j] == 2147483647:
			i += 1
			j -= 1
		elif a[i] + a[j] < 2147483647:
			i += 1
		else:
			j -= 1
	print(z)