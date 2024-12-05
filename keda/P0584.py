s = list(input())
for i in range(len(s)):
	if s[i].isupper():
		s[i] = chr((ord(s[i]) - 70) % 26 + 65)
print(''.join(s))