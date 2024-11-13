for t in range(int(input())):
	n, k = map(int, input().split())
	s = input()
	for i in range(n // 2):
		if s[i] != s[n - i - 1]:
			k -= 1
	if k >= 0 and (n % 2 == 1 or k % 2 == 0):
		print('YES')
	else:
		print('NO')
