for t in range(int(input())):
	s = input()
	t = 'CODETOWN'
	for i in range(8):
		if (t[i] in 'AEIOU') ^ (s[i] in 'AEIOU'):
			print('NO')
			break
	else:
		print('YES')
