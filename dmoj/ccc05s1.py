n = int(input())
for i in range(n):
	s = list(input().replace('-',''))
	for j in range(len(s)):
		if s[j] in 'ABC':
			s[j] = '2'
		if s[j] in 'DEF':
			s[j] = '3'
		if s[j] in 'GHI':
			s[j] = '4'
		if s[j] in 'JKL':
			s[j] = '5'
		if s[j] in 'MNO':
			s[j] = '6'
		if s[j] in 'PQRS':
			s[j] = '7'
		if s[j] in 'TUV':
			s[j] = '8'
		if s[j] in 'WXYZ':
			s[j] = '9'
	s = ''.join(s)
	print(s[:3] + '-' + s[3:6] + '-' + s[6:10])