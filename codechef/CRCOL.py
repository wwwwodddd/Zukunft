for t in range(int(input())):
	n, m, k = map(int, input().split())
	s = input()
	d = min(n, m)
	z = 0
	for i in range(d % len(s))[::-1]:
		n -= 1
		m -= 1
		if s[i] == 'A':
			z += n + m + 1
		else:
			z -= n + m + 1
	a = []
	b = []
	for i in range(len(s))[::-1]:
		if s[i] == 'A':
			a.append(i)
		else:
			b.append(i)
	l = d // len(s)
	z += l * sum(a) * 2 + (l - 1) * (l) * len(s) * len(a) + l * len(a) * (max(n, m) - min(n, m) + 1)
	z -= l * sum(b) * 2 + (l - 1) * (l) * len(s) * len(b) + l * len(b) * (max(n, m) - min(n, m) + 1)

	if z > 0:
		print('Alice')
	elif z < 0:
		print('Bob')
	else:
		print('Draw')