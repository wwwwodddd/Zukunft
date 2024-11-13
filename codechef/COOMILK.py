for t in range(int(input())):
	n = int(input())
	a = input().split()
	for i in range(n):
		if a[i] == 'cookie' and (i + 1 == n or a[i + 1] == 'cookie'):
			print('NO')
			break
	else:
		print('YES')