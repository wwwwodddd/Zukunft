p = 1000000007
n = int(input())
s = [0 for i in range(n + 1)]
t = [0 for i in range(n + 1)]
for i in range(n):
	if i == 0:
		f = n
	elif i == 1:
		f = n * n - n
	else:
		f = n * n - n - (i - 2)
	f = (f + s[i - 2] * (i - 2) - t[i - 2]) % p
	s[i + 1] = (s[i] + f) % p
	t[i + 1] = (t[i] + f * i) % p
print(s[n] % p)