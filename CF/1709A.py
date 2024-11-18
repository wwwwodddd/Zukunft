for t in range(int(input())):
	x = int(input())
	a = [x] + list(map(int, input().split()))
	v = [1, 0, 0, 0]
	v[a[0]] = 1
	v[a[a[0]]] = 1
	v[a[a[a[0]]]] = 1
	if sum(v) == 4:
		print('YES')
	else:
		print('NO')