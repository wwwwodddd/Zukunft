n, k = map(int, input().split())
a = list(map(int, input().split()))
c = [0 for i in range(40)]
for i in a:
	for j in range(40):
		if i >> j & 1:
			c[j] += 1
z = 0
s = 0
for i in range(40)[::-1]:
	if k >> i & 1:
		t = 0
		for j in range(i):
			t += max(c[j], n - c[j]) << j
		z = max(z, s + (c[i] << i) + t)
		s += (n - c[i]) << i
	else:
		s += c[i] << i
z = max(z, s)
print(z)