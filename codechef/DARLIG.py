for t in range(int(input())):
	n, k = map(int, input().split())
	if n % 4 == 0:
		if k == 0:
			print('Off')
		else:
			print('On')
	else:
		if k == 0:
			print('On')
		else:
			print('Ambiguous')
