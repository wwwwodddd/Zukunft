for t in range(int(input())):
	n = int(input())
	a = set(map(int, input().split()))
	a.discard(0)
	if len(a) <= 1:
		print('YES')
	else:
		print('NO')
