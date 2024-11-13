for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	for i in range(n):
		if a[i] > i + 1:
			print('NO')
			break
	else:
		print('YES')
