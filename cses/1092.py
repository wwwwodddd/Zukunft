n = int(input())
s = n * (n + 1) // 2
if s % 2 == 0:
	print('YES')
	a = []
	b = []
	s //= 2
	for i in range(n, 0, -1):
		if s >= i:
			s -= i
			a.append(i)
		else:
			b.append(i)
	print(len(a))
	print(*a)
	print(len(b))
	print(*b)
else:
	print('NO')