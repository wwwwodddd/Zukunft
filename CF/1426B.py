for t in range(int(input())):
	n, m = map(int, input().split())
	f = 0
	for i in range(n):
		if input().split()[1] == input().split()[0]:
			f = 1
	if f and m % 2 == 0:
		print('YES')
	else:
		print('NO')
