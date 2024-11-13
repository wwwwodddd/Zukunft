for t in range(int(input())):
	n, m, k = map(int, input().split())
	s = input()
	z = 0
	for i in range(min(n, m))[::-1]:
		n -= 1
		m -= 1
		if s[i % len(s)] == 'A':
			z += n + m + 1
			print('A+', n + m + 1)
		else:
			z -= n + m + 1
			print('A-', n + m + 1)
	
	print('debug', z)
	if z > 0:
		print('Alice')
	elif z < 0:
		print('Bob')
	else:
		print('Draw')