for t in range(int(input())):
	n = int(input())
	if n & n - 1:
		print('YES')
	else:
		print('NO')