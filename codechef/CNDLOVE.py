for t in range(int(input())):
	n = int(input())
	s = sum(map(int, input().split()))
	if s & 1:
		print('YES')
	else:
		print('NO')