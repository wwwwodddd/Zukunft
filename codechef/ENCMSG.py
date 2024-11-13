for t in range(int(input())):
	n = int(input())
	s = list(input())
	for i in range(0, n - 1, 2):
		s[i], s[i + 1] = s[i + 1], s[i]
	for i in range(n):
		s[i] = chr(219 - ord(s[i]))
	print(''.join(s))