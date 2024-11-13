for t in range(int(input())):
	a, b = map(int, input().split())
	i = 1
	while a >= 0 and b >= 0:
		if i & 1:
			a -= i
		else:
			b -= i
		i += 1
	if a < 0:
		print('Bob')
	else:
		print('Limak')
