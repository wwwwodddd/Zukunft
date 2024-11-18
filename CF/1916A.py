for t in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	x = 2023
	y = 1
	for i in a:
		y *= i
	if x % y == 0:
		print('YES')
		print(x // y, *([1] * (k - 1)))
	else:
		print('NO')