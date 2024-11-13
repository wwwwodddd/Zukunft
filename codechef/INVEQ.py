for t in range(int(input())):
	input()
	s = input()
	z = 0
	for i in range(1, len(s)):
		z += (s[i] != s[i - 1])
	print((z + 1) // 2)