for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(2, n):
		if a[i - 2] < 0:
			print('NO')
			break
		a[i] -= a[i - 2]
		a[i - 1] -= a[i - 2] * 2
	else:
		if a[-1] == 0 and a[-2] == 0:
			print('YES')
		else:
			print('NO')