for t in range(int(input())):
	n = int(input()) - 2
	a = sorted(map(int, input().split()))
	i = 0
	j = len(a) - 1
	while i < j:
		if a[i] * a[j] < n:
			i += 1
		elif a[i] * a[j] > n:
			j -= 1
		else:
			print(a[i], a[j])
			break
