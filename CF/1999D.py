for t in range(int(input())):
	s = list(input())
	t = input()
	j = 0
	for i in range(len(s)):
		if j < len(t) and (s[i] == t[j] or s[i] == '?'):
			s[i] = t[j]
			j += 1
		elif s[i] == '?':
			s[i] = 'a'
	if j == len(t):
		print('YES')
		print(''.join(s))
	else:
		print('NO')