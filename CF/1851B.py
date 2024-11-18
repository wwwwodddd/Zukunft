for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = sorted(a)
	if sum((i - j) % 2 for i, j in zip(a, b)) == 0:
		print('YES')
	else:
		print('NO')