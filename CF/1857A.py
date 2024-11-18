for t in range(int(input())):
	n = int(input())
	if sum(map(int, input().split())) & 1:
		print('NO')
	else:
		print('YES')