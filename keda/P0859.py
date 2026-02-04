n, m = map(int, input().split())
if n < m:
	if n % 2 == 1:
		n += 1
	if m % 2 == 0:
		m += 1
	print(*range(n, m, 2))
else:
	if m % 2 == 1:
		m += 1
	if n % 2 == 0:
		n += 1
	print(*range(m, n, 2)[::-1])
