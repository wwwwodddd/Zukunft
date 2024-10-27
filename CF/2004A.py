for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if n == 2 and abs(a[0] - a[1]) > 1:
		print('YES')
	else:
		print('NO')
