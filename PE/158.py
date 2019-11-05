n = 26


s = 1
ans = 0
for i in range(26):
	s = s * (n - i) / (i + 1)
	t = i + 1
	ans = max(ans, s * (2 ** t - t - 1))

print ans