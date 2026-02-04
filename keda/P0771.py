while True:
	s = input()
	if s == '!':
		break
	s = list(s)
	for i in range(len(s)):
		if s[i].islower():
			s[i] = chr(ord('a') + ord('z') - ord(s[i]))
		elif s[i].isupper():
			s[i] = chr(ord('A') + ord('Z') - ord(s[i]))
	print(''.join(s))