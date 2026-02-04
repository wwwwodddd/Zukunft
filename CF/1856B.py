for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if sum(a) >= n + a.count(1) and n > 1:
		print('YES')
	else:
		print('NO')