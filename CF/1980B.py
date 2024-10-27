for t in range(int(input())):
	n, f, k = map(int, input().split())
	a = [0] + list(map(int, input().split()))
	f = a[f]
	a.sort(reverse=True)
	if f > a[k]:
		print('YES')
	elif f < a[k - 1]:
		print('NO')
	else:
		print('MAYBE')
