for t in range(int(input())):
	m, s = map(int, input().split())
	b = set(map(int, input().split()))
	if len(b) < m:
		print('NO')
	else:
		n = 0
		while s > 0 or b:
			n += 1
			if n in b:
				b.remove(n)
			else:
				s -= n
		if s == 0:
			print('YES')
		else:
			print('NO')
