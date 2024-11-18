for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(1, n):
		if abs(a[i] - a[i - 1]) not in [5, 7]:
			print('NO')
			break
	else:
		print('YES')