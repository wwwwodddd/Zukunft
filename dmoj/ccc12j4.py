k = int(input()) + 3
s = list(input())
for i in range(len(s)):
	s[i] = chr((ord(s[i]) - 65 - (3 * i + k)) % 26 + 65)
print(''.join(s))