for t in range(int(input())):
	k = int(input())
	s = 'O' + '.' * (k - 1) + 'X' * (64 - k)
	for i in range(8):
		print(s[i * 8:i * 8 + 8])