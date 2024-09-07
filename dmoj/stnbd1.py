n = int(input())
a = [int(input()) for i in range(n)]
if a[0] > max(a[1:]):
	print('YES')
else:
	print('NO')
