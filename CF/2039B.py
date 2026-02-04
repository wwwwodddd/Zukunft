def F(s):
	for i in range(1, len(s)):
		if s[i - 1] == s[i]:
			return s[i - 1 : i + 1]
	for i in range(2, len(s)):
		if s[i - 2] != s[i - 1] != s[i] != s[i - 2]:
			return s[i - 2 : i + 1]
	return -1
for t in range(int(input())):
	s = input()
	print(F(s))
