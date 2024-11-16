n, l = map(int, input().split())
a = [int(i) * 1000 for i in map(int, input().split())]
L = 0
R = max(a) + 1
while L < R - 1:
	M = (L + R) // 2
	s = [0]
	for i in a:
		s.append(s[-1] + i - M)
	t = 0
	z = -1
	for i in range(l, n + 1):
		t = min(t, s[i - l])
		z = max(z, s[i] - t)
	if z >= 0:
		L = M
	else:
		R = M
print(L)
