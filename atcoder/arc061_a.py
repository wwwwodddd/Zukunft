s = raw_input()
z = 0
for i in range(len(s)):
	t = 0
	for j in range(len(s) - i):
		t = t * 10 + [1, 2 ** (j - 1)][j > 0]
	z += int(s[i]) * 2 ** i * t
print z