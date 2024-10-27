for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(1, n):
		if abs(a[i] - a[i - 1]) > 1:
			print('YES')
			print(i, i + 1)
			break
	else:
		print('NO')