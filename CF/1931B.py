for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = sum(a) // n
	z = 0
	for i in a:
		z += i - s
		if z < 0:
			print('NO')
			break
	else:
		print('YES')
