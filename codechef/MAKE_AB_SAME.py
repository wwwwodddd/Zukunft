for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	s = set()
	t = set()
	for i in range(n):
		if a[i]:
			s.add(i)
		if b[i]:
			t.add(i)
	r = (t - s)
	if s == t:
		print('YES')
	elif len(s) == 0 or len(s - t) > 0:
		print('NO')
	elif 0 < min(r) and max(r) < n - 1:
		print('YES')
	else:
		print('NO')