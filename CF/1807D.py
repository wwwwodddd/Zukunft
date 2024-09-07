t = int(input())
for tt in range(t):
	n, q = map(int, input().split())
	a = list(map(int, input().split()))
	s = [0]
	for i in a:
		s.append(s[-1] + i)
	for i in range(q):
		l, r, k = map(int, input().split())
		z = (s[l - 1] + s[n] - s[r] + (r - l + 1) * k) % 2
		if z:
			print('YES')
		else:
			print('NO')