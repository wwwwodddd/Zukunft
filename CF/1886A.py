import math
for t in range(int(input())):
	n = int(input())
	if n > 6 and n % 3 != 0:
		print('YES')
		print(1, 2, n - 3)
	elif n > 9 and n % 3 == 0:
		print('YES')
		print(1, 4, n - 5)
	else:
		print('NO')
