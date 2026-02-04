for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	if a[0] == a[-1]:
		print('NO')
	else:
		print('YES')
		print(a[-1], *a[:-1])
