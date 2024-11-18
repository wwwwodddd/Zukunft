for t in range(int(input())):
	n, m = map(int, input().split())
	if n >= m and (n - m) % 2 == 0:
		print('Yes')
	else:
		print('No')
