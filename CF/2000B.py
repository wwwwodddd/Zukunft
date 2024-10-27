for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	l = r = a[0]
	for i in a:
		if i < l - 1 or i > r + 1:
			print('NO')
			break
		l = min(l, i)
		r = max(r, i)
	else:
		print('YES')