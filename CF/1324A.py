import math
for t in range(int(input())):
	n = int(input())
	s = sum(int(i) % 2 for i in input().split())
	if s == 0 or s == n:
		print('YES')
	else:
		print('NO')
