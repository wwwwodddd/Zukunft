s = list(input())
for i in range(len(s)):
	if s[i].islower():
		s[i] = chr((ord(s[i]) - 96) % 26 + 97)
print(''.join(s))