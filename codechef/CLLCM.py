for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if sum(i % 2 == 0 for i in a):
		print('NO')
	else:
		print('YES')