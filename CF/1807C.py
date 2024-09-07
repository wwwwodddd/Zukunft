t = int(input())
for tt in range(t):
	n = int(input())
	s = input()
	if set(s[::2]) & set(s[1::2]):
		print('NO')
	else:
		print('YES')