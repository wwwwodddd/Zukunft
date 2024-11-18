for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if any(abs(a[i] - i - 1) > 1 for i in range(n)):
		print('NO')
	else:
		print('YES')
