for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = sorted(a)
	for i in range(n):
		if b[i] != a[i] and b[i] % b[0] != 0:
			print('NO')
			break
	else:
		print('YES')