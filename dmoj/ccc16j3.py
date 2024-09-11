s = input()
z = 1
for i in range(len(s)):
	l = r = i
	while l >= 0 and r < len(s) and s[l] == s[r]:
		z = max(z, r - l + 1)
		l -= 1
		r += 1
for i in range(1, len(s)):
	l = i - 1
	r = i
	while l >= 0 and r < len(s) and s[l] == s[r]:
		z = max(z, r - l + 1)
		l -= 1
		r += 1
print(z)