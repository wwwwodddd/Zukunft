for t in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	if k > 1 or sorted(a) == a:
		print('YES')
	else:
		print('NO')