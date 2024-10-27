n = int(input())
a = list(map(int, input().split()))
if sum(a) % 2 == 0 and max(a) * 2 <= sum(a):
	print('YES')
else:
	print('NO')