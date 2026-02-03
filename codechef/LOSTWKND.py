for t in range(int(input())):
	a = list(map(int, input().split()))
	if sum(a[:5]) * a[5] <= 120:
		print('No')
	else:
		print('Yes')
