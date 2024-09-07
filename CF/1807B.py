t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in a:
		if i % 2 == 0:
			z += i
		else:
			z -= i
	if z > 0:
		print('YES')
	else:
		print('NO')