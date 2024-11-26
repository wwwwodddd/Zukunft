for t in range(int(input())):
	input()
	a = sorted(map(int, input().split()))
	if a[::2] == a[1::2]:
		print('YES')
	else:
		print('NO')
