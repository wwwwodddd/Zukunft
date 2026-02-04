for t in range(int(input())):
	n, m = map(int, input().split())
	s = input()
	if n % 2 == 0 and s.count('0') <= n // 2 and s.count('1') <= n // 2:
		print('Yes')
	else:
		print('No')
