def M(m, k, s, n):
	if n > m:
		return n - s
	else:
		return M(m, k, s, M(m, k, s, n + k))

'''
m = 30
sk = 7
for s in range(1, 50):
	for i in range(-100, 100):
		if M(m, s + sk, s, i) == i:
			print m, s + sk, s, i
'''

n = 1000000
ans = 0
for sk in range(1, n + 1):
	s = sk
	k = s + sk
	while k <= n:
		ans += sk * n - (s - sk) * sk - sk * (sk - 1) / 2
		s += sk
		k += sk
print ans