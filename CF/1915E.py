for t in range(int(input())):
	n = int(input())
	v = set()
	s = 0
	v.add(s)
	a = list(map(int, input().split()))
	for i in range(n):
		if i & 1:
			s += a[i]
		else:
			s -= a[i]
		if s in v:
			print('YES')
			break
		v.add(s)
	else:
		print('NO')
