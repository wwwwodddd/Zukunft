for t in range(int(input())):
	n, k = map(int, input().split())
	s = input()
	i = 0
	while i < n - i - 2 and s[i] == s[n - i - 1]:
		i += 1
	if i >= k:
		print('YES')
	else:
		print('NO')