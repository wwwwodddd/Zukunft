for t in range(int(input())):
	n = int(input())
	for i in range(11):
		d = n - i * 111
		if d >= 0 and d % 11 == 0:
			print('YES')
			break
	else:
		print('NO')