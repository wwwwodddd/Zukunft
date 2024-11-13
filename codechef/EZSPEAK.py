for t in range(int(input())):
	n = int(input())
	s = input()
	for c in 'aeiou':
		s = s.replace(c, ' ')
	z = 0
	for i in s.split():
		z = max(z, len(i))
	if z > 3:
		print('NO')
	else:
		print('YES')
